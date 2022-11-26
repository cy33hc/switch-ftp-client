#ifndef FTPCLIENT_H
#define FTPCLIENT_H

#include <switch.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <time.h>
#include <string>
#include <vector>
#include "fs.h"

#define FTP_CLIENT_MAX_FILENAME_LEN 128

typedef int (*FtpCallbackXfer)(int64_t xfered, void *arg);

struct ftphandle
{
	char *cput, *cget;
	int handle;
	int cavail, cleft;
	char *buf;
	int dir;
	ftphandle *ctrl;
	int cmode;
	int64_t xfered;
	int64_t xfered1;
	int64_t cbbytes;
	char response[512];
	int64_t offset;
	bool correctpasv;
	FtpCallbackXfer xfercb;
	void *cbarg;
	bool is_connected;
};

class FtpClient
{
public:
	enum accesstype
	{
		dir = 1,
		dirverbose,
		dirmlsd,
		fileread,
		filewrite,
		filereadappend,
		filewriteappend
	};

	enum transfermode
	{
		ascii = 'A',
		image = 'I'
	};

	enum connmode
	{
		pasv = 1,
		port
	};

	enum attributes
	{
		directory = 1,
		readonly = 2
	};

	FtpClient();
	~FtpClient();
	int Connect(const char *host, unsigned short port);
	void SetConnmode(connmode mode);
	int Login(const char *user, const char *pass);
	int Site(const char *cmd);
	int Raw(const char *cmd);
	int SysType(char *buf, int max);
	int Mkdir(const char *path);
	int Chdir(const char *path);
	int Cdup();
	int Rmdir(const char *path);
	int Rmdir(const char *path, bool recursive);
	int Pwd(char *path, int max);
	int Size(const char *path, int64_t *size, transfermode mode);
	int ModDate(const char *path, char *dt, int max);
	int Get(const char *outputfile, const char *path, transfermode mode, int64_t offset = 0);
	int Put(const char *inputfile, const char *path, transfermode mode, int64_t offset = 0);
	int Rename(const char *src, const char *dst);
	int Delete(const char *path);
	std::vector<std::string> ListFiles(const char *path, bool includeSubDir = false);
	std::vector<FsEntry> ListDir(const char *path);
	void SetCallbackXferFunction(FtpCallbackXfer pointer);
	void SetCallbackArg(void *arg);
	void SetCallbackBytes(int64_t bytes);
	bool Noop();
	bool IsConnected();
	char *LastResponse();
	long GetIdleTime();
	int Quit();

private:
	ftphandle *mp_ftphandle;
	struct tm cur_time;
	timeval tick;

	int FtpSendCmd(const char *cmd, char expected_resp, ftphandle *nControl);
	ftphandle *RawOpen(const char *path, accesstype type, transfermode mode);
	int RawClose(ftphandle *handle);
	int RawWrite(void *buf, int len, ftphandle *handle);
	int RawRead(void *buf, int max, ftphandle *handle);
	int ReadResponse(char c, ftphandle *nControl);
	int Readline(char *buf, int max, ftphandle *nControl);
	int Writeline(char *buf, int len, ftphandle *nData);
	void ClearHandle();
	int FtpOpenPasv(ftphandle *nControl, ftphandle **nData, transfermode mode, int dir, char *cmd);
	int FtpOpenPort(ftphandle *nControl, ftphandle **nData, transfermode mode, int dir, char *cmd);
	int FtpAcceptConnection(ftphandle *nData, ftphandle *nControl);
	int CorrectPasvResponse(int *v);
	int FtpAccess(const char *path, accesstype type, transfermode mode, ftphandle *nControl, ftphandle **nData);
	int FtpXfer(const char *localfile, const char *path, ftphandle *nControl, accesstype type, transfermode mode);
	int FtpWrite(void *buf, int len, ftphandle *nData);
	int FtpRead(void *buf, int max, ftphandle *nData);
	int FtpClose(ftphandle *nData);
	int ParseDirEntry(char *line, FsEntry *dirEntry);
	int ParseMLSDDirEntry(char *line, FsEntry *dirEntry);
};

#endif