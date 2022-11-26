#ifndef LAUNCHER_CONFIG_H
#define LAUNCHER_CONFIG_H

#include <string>
#include <vector>
#include <algorithm>
#include <map>

#define APP_ID "switch-ftp-client"
#define DATA_PATH "/switch/" APP_ID
#define CONFIG_INI_FILE DATA_PATH "/config.ini"

#define CONFIG_GLOBAL "Global"

#define CONFIG_DEFAULT_STYLE_NAME "Default"
#define CONFIG_SWAP_XO "swap_xo"

#define CONFIG_FTP_SERVER_NAME "ftp_server_name"
#define CONFIG_FTP_SERVER_IP "ftp_server_ip"
#define CONFIG_FTP_SERVER_PORT "ftp_server_port"
#define CONFIG_FTP_SERVER_USER "ftp_server_user"
#define CONFIG_FTP_SERVER_PASSWORD "ftp_server_password"
#define CONFIG_FTP_TRANSFER_MODE "ftp_transfer_mode"

#define CONFIG_LAST_SITE "last_site"

#define CONFIG_LOCAL_DIRECTORY "local_directory"
#define CONFIG_REMOTE_DIRECTORY "remote_directory"

#define CONFIG_LANGUAGE "language"

struct FtpSettings
{
    char site_name[32];
    char server_ip[16];
    char username[33];
    char password[25];
    int server_port;
    bool pasv_mode;
};

extern bool swap_xo;
extern std::vector<std::string> sites;
extern std::map<std::string, FtpSettings> site_settings;
extern char local_directory[255];
extern char remote_directory[255];
extern char app_ver[6];
extern char last_site[32];
extern char display_site[32];
extern char language[128];
extern FtpSettings *ftp_settings;

namespace CONFIG
{
    void LoadConfig();
    void SaveConfig();
    void RemoveFromMultiValues(std::vector<std::string> &multi_values, std::string value);
    void ParseMultiValueString(const char *prefix_list, std::vector<std::string> &prefixes, bool toLower);
    std::string GetMultiValueString(std::vector<std::string> &multi_values);
}
#endif
