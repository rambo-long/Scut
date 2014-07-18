#ifndef _SCUTWEBVIEW_H_
#define _SCUTWEBVIEW_H_
#include "CCPlatformMacros.h"
#include <string>
#include "ccTypes.h"
#include "CCDirector.h"
//#include "cocos2d.h"
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#include "Winuser.h"
#endif

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include "./Android/AndroidWindow.h"
#endif
#include "../cocos2dx_support/CCLuaEngine.h"	

namespace ScutCxControl
{

	/**
	* @brief  WEB ҳ��ؼ�
	* @remarks   
	* @see		
	*/
	class LUA_DLL ScutWebView
	{
	public:
		ScutWebView(void);
		virtual ~ScutWebView(void);
		//��ʼ���༭��ؼ�

		/**
		* @brief  ����WEB �ؼ��� 
		* @n<b>��������</b>					: init
		* @n@param  szUrl url��ַ
		* @param    CCRect λ�úʹ�С,  ��IPHOEN ƽ̨��Ч��ANDROID ƽ̨��Ч
		* @param    char ������ʾ,   ��IPHOEN ƽ̨��Ч��ANDROID ƽ̨��Ч
		* @param    char* ���ذ���NormalͼƬ ,  ��IPHOEN ƽ̨��Ч��ANDROID ƽ̨��Ч
		* @param    char* ���ذ���PushDownͼƬ ,  ��IPHOEN ƽ̨��Ч��ANDROID ƽ̨��Ч
		* @remarks  IPHOEN ��ANDROID ƽ̨���� �� 
		* @see		
		*/
		bool init(char* szUrl, cocos2d::CCRect rcScreenFrame, const char* szTitle, const char* szNormal, const char* szPushDown);
		void close();
		void switchUrl(const char* szUrl);
	private:
		void* m_pInnerWebView;
	};
}
#endif
