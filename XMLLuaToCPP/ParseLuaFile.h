#ifndef _PARSE_LUA_FILE_H
#define _PARSE_LUA_FILE_H

#include "Common.h"
#include <string>
using namespace std ;

struct _FileLine
{
	string m_strLine;
};
typedef vector<_FileLine> vec_FileLine;

//�����ļ�����������ͷ�ļ�
bool Parse_Lua_File(const char* pFileName, vec_FileLine& obj_vec_FileLine);

//�ϲ��滻����
bool Searsh_Lua_File(const char* pFunctionName, const char* pFunctionLine, string strFuncBody, vec_FileLine& obj_vec_FileLine);

//�����ļ�
bool Save_Lua_File(const char* pFileName, vec_FileLine& obj_vec_FileLine);

#endif
