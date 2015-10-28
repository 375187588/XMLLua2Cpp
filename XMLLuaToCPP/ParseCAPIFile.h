#ifndef _PARSE_C_API_FILE_H
#define _PARSE_C_API_FILE_H

#include "Common.h"
#include <string>
using namespace std ;

//��¼���õ�ͷ�ļ�
struct _FileInclude
{
	string m_strIncoude;
};
typedef vector<_FileInclude> vecFileInclude;

//��¼���õĺ��������
struct _FunctionCode
{
	char   m_szFuncName[200];
	string m_strCode;

	_FunctionCode()
	{
		m_szFuncName[0] = '\0';
	}
};
typedef vector<_FunctionCode> vecFunctionCode;

//�ļ������Ϣ
struct _File_Info
{
	vecFileInclude  m_vecFileInclude;
	vecFunctionCode m_vecFunctionCode;
};

//������������
bool Parse_Function_Name(char* pLine, char* pFunctionName);

//����������ͷ�ļ�
void Parse_File_Include(char* pData, int nFileSize, _File_Info& obj_File_Info);

//�������������к������ͺ�����
void Parse_File_Function_Info(char* pData, int nFileSize, _File_Info& obj_File_Info);

//�����ļ�����������ͷ�ļ�
bool Parse_CAPI_H_File(const char* pFileName, _File_Info& obj_File_Info);

#endif