#ifndef _COMMON_H
#define _COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#include <vector>
using namespace std;

//�Զ�����Lua�ļ�
//add by freeeyes

#define MAX_BUFF_50 50

//��������
enum EM_PARAM_TYPE
{
	PARAM_TYPE_IN  = 0,    //��ڲ���
	PARAM_TYPE_OUT,        //���ڲ���  
};

//��������
enum EM_PARAM_CLASS
{
	PARAM_CLASS_INT = 0,   //��������
	PARAM_CLASS_STRING,    //�ַ������� 
	PARAM_CLASS_VOID,      //ָ������
};

//��������
struct _Function_Param
{
	char           m_szParamName[MAX_BUFF_50];   //��������
	char           m_szParamType[MAX_BUFF_50];   //�������ͣ��ַ����� 
	EM_PARAM_TYPE  m_emParamType;                //��������
	EM_PARAM_CLASS m_emParamClass;               //��������
	int            m_nLength;                    //��������

	_Function_Param()
	{
		m_szParamName[0] = '\0';
		m_emParamType    = PARAM_TYPE_IN;
		m_emParamClass   = PARAM_CLASS_INT;
		m_nLength        = 0;
	}
};
typedef vector<_Function_Param> vecParamList;

//Lua������Ϣ
struct _Function_Info
{
	char m_szFunctionName[MAX_BUFF_50];
	char m_szDesc[MAX_BUFF_50];
	vecParamList m_vecParamList;

	_Function_Info()
	{
		m_szFunctionName[0] = '\0';
		m_szDesc[0]         = '\0';
	}
};
typedef vector<_Function_Info> vecFunctionList;

//Lua�ļ�
struct _LuaFile_Info
{
	char m_szFileName[MAX_BUFF_50];
	char m_szDesc[MAX_BUFF_50];
	vecFunctionList m_vecFunctionList;

	_LuaFile_Info()
	{
		m_szFileName[0] = '\0';
		m_szDesc[0]     = '\0';
	}
};
typedef vector<_LuaFile_Info> vecLuaFileList;

//Lua������Ϣ
struct _Project_Lua_Info
{
	char m_szProjectName[MAX_BUFF_50];
	vecLuaFileList m_vecLuaFileList;

	_Project_Lua_Info()
	{
		m_szProjectName[0] = '\0';
	}
};

//Lua�ļ�
struct _CppFile_Info
{
	char m_szFileName[MAX_BUFF_50];
	char m_szDesc[MAX_BUFF_50];
	vecFunctionList m_vecFunctionList;

	_CppFile_Info()
	{
		m_szFileName[0] = '\0';
		m_szDesc[0]     = '\0';
	}
};
typedef vector<_CppFile_Info> vecCppFileList;

//Cpp������Ϣ
struct _Project_Cpp_Info
{
	char m_szProjectName[MAX_BUFF_50];
	vecCppFileList m_vecCppFileList;

	_Project_Cpp_Info()
	{
		m_szProjectName[0] = '\0';
	}
};

//���Բ������ݽṹ��
struct _Test_API_Param_Info
{
	char           m_szParamName[MAX_BUFF_50];
	EM_PARAM_CLASS m_emParamClass;
	char           m_szParamClass[MAX_BUFF_50];
	char           m_szValue[MAX_BUFF_50];

	_Test_API_Param_Info()
	{
		m_szParamName[0] = '\0';
		m_emParamClass   = PARAM_CLASS_VOID;
		m_szParamClass[0] = '\0';
		m_szValue[0]     = '\0';
	}
};
typedef vector<_Test_API_Param_Info> vecTestLuaParamIn;
typedef vector<_Test_API_Param_Info> vecTestLuaParamOut;

//����Lua API����
struct _Test_API_Lua_Function_Info
{
	char               m_szName[MAX_BUFF_50];
	char               m_szLuaFuncName[MAX_BUFF_50];
	int                m_nTestCount;
	vecTestLuaParamIn  m_vecTestLuaParamIn;
	vecTestLuaParamOut m_vecTestLuaParamOut;

	_Test_API_Lua_Function_Info()
	{
		m_szName[0]        = '\0';
		m_szLuaFuncName[0] = '\0';
		m_nTestCount       = 0;
	}
};
typedef vector<_Test_API_Lua_Function_Info> vecTestAPIInfo;

struct _Test_API
{
	char m_szProjectName[MAX_BUFF_50];
	vecTestAPIInfo m_vecTestAPIInfo;

	_Test_API()
	{
		m_szProjectName[0] = '\0';
	}
};

//��¼�����������͵�����ģ��
struct _Base_Data_Info
{
	char m_szDataName[MAX_BUFF_50];
	char m_szDataType[MAX_BUFF_50];
	int  m_nDataLen;
	char m_szDataDesc[MAX_BUFF_50];

	_Base_Data_Info()
	{
		m_szDataName[0] = '\0';
		m_szDataType[0] = '\0';
		m_szDataDesc[0] = '\0';
		m_nDataLen      = 0;
	}
};
typedef vector<_Base_Data_Info> vecBaseDataInfo;

//�ṹ���������ṹ��
struct _Base_Data_Struct
{
	char m_szStructName[MAX_BUFF_50];
	vecBaseDataInfo m_vecBaseDataInfo;

	_Base_Data_Struct()
	{
		m_szStructName[0] = '\0';
	}
};
typedef vector<_Base_Data_Struct> vecBaseDataStruct;

struct _Base_Data_Group
{
	char m_szProjectName[MAX_BUFF_50];
	vecBaseDataStruct m_vecBaseDataStruct;

	_Base_Data_Group()
	{
		m_szProjectName[0] = '\0';
	}
};

static void sprintf_safe(char* szText, int nLen, const char* fmt ...)
{
	if(szText == NULL)
	{
		return;
	}

	va_list ap;
	va_start(ap, fmt);

	vsnprintf(szText, nLen, fmt, ap);
	szText[nLen - 1] = '\0';

	va_end(ap);
};

#endif
