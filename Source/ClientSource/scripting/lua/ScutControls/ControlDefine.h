#ifndef _CONTROL_DEFINE_H_
#define _CONTROL_DEFINE_H_
#include "CCPlatformMacros.h"
#include "../cocos2dx_support/CCLuaEngine.h"
namespace ScutCxControl
{

typedef  enum
{
    PARENT_CENTER,
    VERTICAL_TOP,
    VERTICAL_BOTTOM,
    HORIZONTAL_LEFT,
    HORIZONTAL_RIGHT,
    ABS_WITH_PIXEL,
    ABS_WITH_PERCENT,
    REF_PREV_X_INC,
    REF_PREV_X_DEC,
    REF_PREV_Y_INC,
    REF_PREV_Y_DEC,
    REL_FLOW
} LAYOUT_TYPE;

union _Val
{
	/**
	* @brief  ����ֵ
	* @remarks   
	* @see		
	*/
	float pixel_val;
	/**
	* @brief  �ٷֱ�ֵ
	* @remarks   
	* @see		
	*/
	float percent_val;
};


	/**
	* @brief  �б�ؼ�����ֲ���-�������
	* @remarks   
	* @see		
	*/
struct LUA_DLL LayoutParamVal
{
	/**
	* @brief  ����ֵ
	* @remarks   
	* @see		
	*/
    LAYOUT_TYPE t;
    _Val val;
	LayoutParamVal()
	{
		val.percent_val = 0;
		val.pixel_val   = 0;
	}
};


/**
	* @brief  �б�ؼ�����ֲ���
	* @remarks   
	* @see		
	*/
struct LUA_DLL LayoutParam
{
public:
    LayoutParamVal val_x;
    LayoutParamVal val_y;
    float          padding;
    bool           wrap;
	LayoutParam()
	{
		padding = 0;
		wrap    = true;
	}
	virtual ~LayoutParam()
	{

	}
};

static inline LayoutParam
CxLayout()
{
	return LayoutParam();
}
}

#endif