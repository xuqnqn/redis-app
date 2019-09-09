#ifndef CONFIGFILEREADER_H_
#define CONFIGFILEREADER_H_

#include <stdint.h>
#include <map>
#include <string>
#include <string.h>
#include <stdio.h>
#include <errno.h>
using namespace std;

class CStrExplode
{
public:
    CStrExplode(char* str, char seperator);
    virtual ~CStrExplode();

    uint32_t GetItemCnt() { return m_item_cnt; }
    char* GetItem(uint32_t idx) { return m_item_list[idx]; }

private:
    uint32_t	m_item_cnt;
    char** 		m_item_list;
};

class CConfigFileReader
{
public:
	CConfigFileReader(const char* filename);
	~CConfigFileReader();

    char* GetConfigName(const char* name);
    int SetConfigValue(const char* name, const char*  value);

private:
    void _LoadFile(const char* filename);
    int _WriteFile(const char*filename = NULL);
    void _ParseLine(char* line);
    char* _TrimSpace(char* name);
    bool m_load_ok;
    map<string, string> m_config_map;
    string m_config_file;
};


#endif /* CONFIGFILEREADER_H_ */
