
// Water_(JKH_version).h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CWaterJKHversionApp:
// Сведения о реализации этого класса: Water_(JKH_version).cpp
//

class CWaterJKHversionApp : public CWinApp
{
public:
	CWaterJKHversionApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CWaterJKHversionApp theApp;
