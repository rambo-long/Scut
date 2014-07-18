/****************************************************************************
Copyright (c) 2013-2015 Scutgame.com

http://www.scutgame.com

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/
#ifndef _SCUTEDIT_H_
#define _SCUTEDIT_H_
#include "CCPlatformMacros.h"
#include <string>
#include "ccTypes.h"
#include "CCDirector.h"
#include "CCScriptSupport.h"
//#include "cocos2d.h"
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#include "Winuser.h"
#endif

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include "./ANDROID/AndroidWindow.h"
#endif
#include "../cocos2dx_support/CCLuaEngine.h"

using namespace cocos2d;

namespace ScutCxControl
{
	/**
	* @brief  �༭��ؼ�
	* @remarks   
	* @see		
	*/
	class LUA_DLL CScutEdit
	{
	public:
		CScutEdit(void);
		virtual ~CScutEdit(void);
		 
		/**
		* @brief  ��ʼ���༭��ؼ��� 
		* @n<b>��������</b>					: init
		* @n@param  bool �Ƿ����
		* @param    bool �Ƿ����뷽ʽ
		* @remarks
		* @see		
		*/
		bool init(bool bMultiline = false, bool bPwdMode = false, cocos2d::ccColor4B* pBackColor = 0, cocos2d::ccColor4B* pForeColor = 0, cocos2d::CCPoint* pLocation = 0, cocos2d::CCSize* pSize = 0);
		 
		/**
		* @brief  ���ñ༭���λ���Լ���С 
		* @n<b>��������</b>					: setRect
		* @n@param  CCRect λ���Լ���С 
		* @remarks
		* @see		
		*/
		void setRect(cocos2d::CCRect rcEdit);

		/**
		* @brief  ȡ�༭��ؼ��ı�
		* @n<b>��������</b>					: GetEditText
		* @remarks
		* @see		
		*/
		std::string GetEditText();
		void release();
		/**
		* @brief  ��༭��ؼ��Ƿ�ɼ� 
		* @n<b>��������</b>					: GetEditText
		* @remarks
		* @see		
		*/
		void setVisible(bool bVisible);
		/**
		* @brief  ��༭��ؼ��Ƿ����  
		* @n<b>��������</b>					: GetEditText
		* @remarks
		* @see		
		*/
		void setEnabled(bool bEnable);



		/**
		* @brief  ��༭��ؼ����ı�  
		* @n<b>��������</b>					: GetEditText
		* @remarks
		* @see		
		*/
		void setText(std::string strText);

		/**
		* @brief  ���������
		* @n<b>��������</b>					: setMaxText
		* @n@param  int ����
		* @remarks   
		* @see		
		*/
		void setMaxText(int nTextCount);
	
		void setInputNumber();
		void OnTextChanged()
		{
			if (m_TextChangedFuncName.size() && CCScriptEngineManager::sharedManager()->getScriptEngine())
			{
				CCScriptEngineManager::sharedManager()->getScriptEngine()->executeGlobalFunction(m_TextChangedFuncName.c_str());
			}
		}

		void registerTextChangedScript(const char* pszFunctionName)
		{
			m_TextChangedFuncName = pszFunctionName;
		}

		/**
		* @brief  �������С
		* @n<b>��������</b>					: SetTextSize
		* @n@param  int �����
		* @remarks   WIN32 ƽ̨�������ã�IPHONE ƽ̨��ANDROID ƽ̨��Ч
		* @see		
		*/
	    void SetTextSize(int nTextSize);
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_MAC)
		void hiddenTextPanel();
#else
		void hiddenTextPanel(){};
#endif
	private:
#if  (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
		HWND	m_hEditWin;
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
		long	m_hEditWin;
#endif
		int    m_nTag;		
	private:			
		std::string m_TextChangedFuncName;
	};
}
#endif
