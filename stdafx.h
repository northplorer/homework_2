// stdafx.h : ���� ��������� ���� ��������� �ʴ�
// ǥ�� �ý��� ���� ���� �� ������Ʈ ���� ���� ������
// ��� �ִ� ���� �����Դϴ�.
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>



// TODO: ���α׷��� �ʿ��� �߰� ����� ���⿡�� �����մϴ�.
#include <Windows.h>
#include <stdint.h>
#include <crtdbg.h>
#include <strsafe.h>
#include <string>
#include <handleapi.h>

void print(_In_ const char* fmt, _In_ ...);
bool is_file_existsW(_In_ const wchar_t* file_path);
wchar_t* get_current_directory(void);