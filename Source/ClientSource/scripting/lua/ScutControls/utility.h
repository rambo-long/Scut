#ifndef _CUTILITY_H_
#define _CUTILITY_H_
#include <string>
#include "CCPlatformMacros.h"
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#include <iconv.h>
#endif
#include "../cocos2dx_support/LuaEngine.h"
#include "cocos2d.h"
#include "CCGeometry.h"
#include "platform.h"

//using namespace cocos2d;



/**
* @brief ����X��Y����CCPoint
* @n<b>��������</b>					: PT
* @n@param  float x����
* @param    float y����
* @remarks   
* @see		
*/



cocos2d::CCPoint PT(float x, float y);



/**
* @brief ����W��H����CCSize
* @n<b>��������</b>					: SIZE
* @n@param  float ��
* @param    float ��
* @remarks   
* @see		
*/

cocos2d::CCSize SZ(float width, float height); 



/**
* @brief  ������Ӧ��ǰ���ű��ʵ�X����
* @n<b>��������</b>					: SX
* @n@param  float x
* @remarks   
* @see		
*/
float SX(float x);


/**
* @brief  ������Ӧ��ǰ���ű��ʵ�Y����
* @n<b>��������</b>					: SY
* @n@param  float y
* @remarks   
* @see		
*/
float SY(float y);



namespace NdCxControl
{

	/**
	* @brief  ����ת���ַ���
	* @n<b>��������</b>					: IntToString
	* @n@param  int ����
	* @return  �ַ���
	* @remarks   
	* @see		
	*/
	std::string IntToString(int nValue);

	/**
	* @brief  DWORDת���ַ���
	* @n<b>��������</b>					: DWORDToString
	* @n@param  unsigned ��ֵ
	* @return  �ַ���
	* @remarks   
	* @see		
	*/
	std::string DWORDToString(unsigned long dwValue);


	/**
	* @brief  �ַ�����ת��Utf8תΪGB2312
	* @n<b>��������</b>					: Utf8ToGB2312
	* @n@param  char * �ַ���
	* @param  int �ַ�������
	* @remarks   
	* @see		
	*/
	std::string  Utf8ToGB2312(const char *src, int src_size);

	/**
	* @brief  �ַ�����ת��GB2312תΪUtf8
	* @n<b>��������</b>					: GB2312ToUtf8
	* @n@param  char * �ַ���
	* @param  int �ַ�������
	* @remarks   
	* @see		
	*/
	std::string  GB2312ToUtf8(const char *src, int src_size);


	/**
	* @brief  ���������
	* @n<b>��������</b>					: Distance
	* @n@param  CCPoint ��ʼ��
	* @param  CCPoint ��ֹ��
	* @remarks   
	* @see		
	*/
	float Distance(cocos2d::CCPoint pt1,cocos2d::CCPoint pt2);


	/**
	* @brief  ������Ӧ��ǰ���ű��ʵ�X����
	* @n<b>��������</b>					: SCALEX
	* @n@param  float x
	* @remarks   
	* @see		
	*/
	float SCALEX(int x);


	/**
	* @brief  ������Ӧ��ǰ���ű��ʵ�Y����
	* @n<b>��������</b>					: SCALEY
	* @n@param  float y
	* @remarks   
	* @see		
	*/
	float SCALEY(int y);



	/**
	* @brief  ���ļ���ȡTEXTUR
	* @n<b>��������</b>					: TEXTURE
	* @n@param  string �ļ���
	* @remarks   
	* @see		
	*/
	cocos2d::CCTexture2D * TEXTURE(const std::string & strFile);




	/**
	* @brief �ļ�����ת��
	* @remarks   
	* @see		
	*/
	class LUA_DLL CodeConverter 
	{
	private:
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
		iconv_t cd;
#endif
	public:
		CodeConverter(const char *from_charset, const char *to_charset);
		~CodeConverter();
		int convert(const char *inbuf, int inlen, char *outbuf, int outlen);
	};


	/**
	* @brief ���ù���
	* @remarks   
	* @see		
	*/
	class LUA_DLL CUtility
	{
	public:
		static CUtility* sharedUtility(void);
		//URL����
		float GetScaleX(int x){return (float)x*m_fScaleX;}
		float GetScaleY(int y){return (float)y*m_fScaleY;}
		static cocos2d::CCTexture2D *getTextureFrom(const std::string &file1);
		int getMainBkWidth();
		int getMainBkHeight();
		void setMainBkWidth(int nWidth);
		void setMainBkHeight(int nHeight);


	private:
		CUtility(void);
	private:
		float m_fScaleX;
		float m_fScaleY;
		int m_nMainBKWidth ;
		int m_nMainBKHeight ;
	};

}
#endif
