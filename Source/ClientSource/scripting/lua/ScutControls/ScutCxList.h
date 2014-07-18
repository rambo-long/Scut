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
#ifndef __SCUTCX_LIST_H__
#define __SCUTCX_LIST_H__

#include <time.h>
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
#include "platform.h"
#include "ScutCxListItem.h"
#include <vector>
#include "../cocos2dx_support/CCLuaEngine.h"
#include "ScutListLoaderListener.h"


/*
*  LIST �ؼ������˺���ģʽ�ͷ�ҳЧ���� �ӿ���ɰ汾���ݡ�
*ScutCxList(float row_height, 
*			ccColor4B bg_color, 
*			CCSize size,
*			bool horizontal_mode=false
*			);
*���һ����������ģ��ģʽ�ģ�Ĭ��Ϊ��ģʽ��
*
* .���Ƿ�ҳ
*		void setPageTurnEffect(bool bPageTurn);
*		bool getPageTurnEffect();
*		 
*		//��ҳ�ļ�¼�� ,Ĭ��Ϊһ
*		void setRecodeNumPerPage(int nNumber);
*		int  getRecodeNumPerPage();
*/



using namespace cocos2d;
namespace  ScutCxControl 
{
	class ScutCxListItem;
	typedef enum  
	{
		LS_WAITING,
		LS_TRACKINGTOUCH,
	} LIST_STATE;


	typedef enum  
	{
		SLIDER_NO,
		SLIDER_H,
		SLIDER_W,		
	} LIST_SLIDE_DIR;


	/**
	* @brief  �б������¼�������
	* @remarks   
	* @see		
	*/
	struct LUA_DLL ScutCxListItemClickListener
	{
		virtual void onClick(int index, ScutCxListItem *item) = 0;
	};

	/**
	* @brief  �б�ؼ�
	* @remarks   
	* @see		
	*/
	class LUA_DLL ScutCxList : public CCLayerColor
	{
	public:

		virtual ~ScutCxList(void);

		static ScutCxList* node(float row_height, 
			ccColor4B bg_color, 
			CCSize size);

	public:
		/**
		* @brief  ��ʼ���б�ؼ�
		* @n<b>��������</b>					: addListItem
		* @n@param   float   row_height ÿ�л��еĿ�/�߶�
		* @param  ccColor4B bg_color ����ɫ
		* @param  CCSize size  �����С
		* @param  bool horizontal_mode �Ƿ�ģ��ģʽ
		* @return   
		* @remarks  
		* @see		
		*/
		ScutCxList(float row_height, 
			ccColor4B bg_color, 
			CCSize size,
			bool horizontal_mode=false
			);

		/**
		* @brief Ϊ��������һ������
		* @n<b>��������</b>					: addListItem
		* @n@param   ScutCxListItem   item
		* @param   ScutCxListItem*   item
		* @return  bool  �Ƿ񻬶�����ЩITEM�ɼ�
		* @remarks �ɰ汾�ӿ���ΪaddChild,���ڽű���ʹ��������CCNODE�Ļ���������
		* @see		
		*/
		int addListItem(ScutCxListItem *item, bool scroll_to_view = true);


		/**
		* @brief ɾ��ָ������
		* @n<b>��������</b>					: DeleteChild
		* @n@param   ScutCxListItem*   item
		* @remarks 
		* @see		
		*/
		void DeleteChild(ScutCxListItem* child);
		/**
		* @brief ɾ��ָ������
		* @n<b>��������</b>					: DeleteChild
		* @n@param   int   �ڼ���ITEM
		* @remarks 
		* @see		
		*/
		void DeleteChild(int nIndex);


		/**
		* @brief ��������
		* @n<b>��������</b>					: insertChild
		* @n@param   ScutCxListItem *item
		* @param   int   λ��������
		* @remarks 
		* @see		
		*/
		int insertChild(ScutCxListItem *item, int nIndex);

		/**
		* @brief ��ȡָ������������
		* @n<b>��������</b>					: getChild
		* @n@param   ScutCxListItem *item
		* @param   int   λ��������
		* @remarks 
		* @see		
		*/
		ScutCxListItem *getChild(int row_index);


		/**
		* @brief ����б�����
		* @remarks 
		* @see		
		*/
		void clear(void);

		/**
		* @brief ѡ���б�ָ����/��
		* @remarks 
		* @see		
		*/
		void selectChild(int row_index);

		/**
		* @brief ��ȡ��ǰѡ�е�����
		* @remarks 
		* @see		
		*/
		ScutCxListItem *getSelectedChild(void);


		/**
		* @brief �軭����ɫ
		* @remarks 
		* @see		
		*/
		void setLineColor(ccColor3B &color);


		/**
		* @brief ��ѡ��ʱ������ɫ
		* @remarks 
		* @see		
		*/
		void setSelectedItemColor(ccColor3B &start_color, ccColor3B &end_color);


		/**
		* @brief ��ȡ��������
		* @remarks 
		* @see		
		*/
		int getChildCount(void);

		///////////////////////////
		//���±��������item֮ǰ����


		/**
		* @brief �����Ƿ����ģʽ
		* 
		* 
		* @n<b>��������</b>					: setHorizontal
		* @n@param   bool     bHorizontal : �Ƿ����ģʽ�� Ĭ��Ϊ[FALSE]����
		* @return  ��
		* @remarks ���������item֮ǰ����
		* @see		
		*/

		void setHorizontal(bool bHorizontal=false);


		/**
		* @brief  ��ȡ�Ƿ����ģʽ
		* 
		* 
		* @n<b>��������</b>					: isHorizontal_mode
		* @return  TRUE ����ģʽ�� FALSE ����ģʽ
		* @remarks ���������item֮ǰ����
		* @see		
		*/
		bool isHorizontal_mode();



		/**
		* @brief  �����б�ؼ��߶�
		* 
		* 
		* @n<b>��������</b>					: setRowHeight
		* @n@param  float �߶�
		* @return  void
		* @remarks ���������item֮ǰ����
		* @see		
		*/
		void setRowHeight(float height);


		/**
		* @brief  �����б�ؼ����
		* @n<b>��������</b>					: setRowWidth
		* @n@param  int ���
		* @return  void
		* @remarks ���������item֮ǰ����
		* @see		
		*/
		void setRowWidth(float width);
		/////////////////////////////////



		/**
		* @brief  �����Ƿ�ҳ
		* 
		* 
		* @n<b>��������</b>					: setPageTurnEffect
		* @n@param  bool �Ƿ�ҳ
		* @return  void
		* @remarks
		* @see		
		*/
		void setPageTurnEffect(bool bPageTurn);


		/**
		* @brief  ��ȡ�Ƿ�ҳ
		* 
		* 
		* @n<b>��������</b>					: getPageTurnEffect
		* @return  bool �Ƿ�ҳ
		* @remarks
		* @see		
		*/
		bool getPageTurnEffect();


		/**
		* @brief  ����ָ��ҳ
		* @n<b>��������</b>					: setPageTurnEffect
		* @n@param  int ����ָ��ҳ
		* @return  void
		* @remarks
		* @see		
		*/
		void turnToPage(int nPageIndex);

		/**
		* @brief  ��ҳ�ļ�¼�� ,Ĭ��Ϊһ
		* 
		* 
		* @n<b>��������</b>					: setRecodeNumPerPage
		* @n@param  int һ���ļ�¼��
		* @return  void
		* @remarks
		* @see		
		*/
		void setRecodeNumPerPage(int nNumber);


		/**
		* @brief  ��ȡҳ�ļ�¼��  
		* 
		* 
		* @n<b>��������</b>					: getRecodeNumPerPage
		* @return  int һ���ļ�¼��
		* @remarks
		* @see		
		*/
		int  getRecodeNumPerPage();


		/**
		* @brief  ��̬�����Ƿ���Ӧ�¼� 
		* @n<b>��������</b>					: SetSilence
		* @n@param  bool �Ƿ���Ӧ�¼�
		* @remarks
		* @see		
		*/
		void SetSilence(bool bSilence);


		/**
		* @brief  ��ȡ�����б�ؼ�����ĸ߶� 
		* @n<b>��������</b>					: getRowHeight
		* @see		
		*/
		float getRowHeight(void);

		/**
		* @brief  ��ȡ�����б�ؼ�����Ŀ�� 
		* @n<b>��������</b>					: getRowWidth
		* @see		
		*/
		float getRowWidth(void);





		/**
		* @brief  ע��C++ LOADER �¼� 
		* @n<b>��������</b>					: registerLoaderListern
		* @n@param  CNdListLoaderListener �¼�������
		* @remarks
		* @see		
		*/
		void	registerLoaderListern(const CScutListLoaderListener* pListener)
		{
			m_pLoaderListener = const_cast<CScutListLoaderListener*>(pListener);
		}



		/**
		* @brief  LUA unselect �¼��ص�ע��, �ص�function ��һ��int ������ΪItem��indexֵ
		* @n<b>��������</b>					: registerUnselectEvent
		* @n@param  char*  �ص���
		* @remarks
		* @see		
		*/	 
		void registerUnselectEvent(int fun);

		/**
		* @brief  LUA LOADER �¼��ص�ע�� ���ص�function ��һ��int ������ΪĿ��ҳ��ֵ
		* @n<b>��������</b>					: registerLoadEvent
		* @n@param  char*  �ص���
		* @remarks
		* @see		
		*/	 
		virtual void registerLoadEvent(int fun);
		/**
		* @brief  LUA UNLOADER �¼��ص�ע�� ���ص�function ��һ��int ������ΪĿ��ҳ��ֵ
		* @n<b>��������</b>					: registerUnloadEvent
		* @n@param  char*  �ص���
		* @remarks
		* @see		
		*/
		virtual void registerUnloadEvent(int fun);

		void unregisterUnloadEvent();
		void unregisterLoadEvent();
		void unregisterUnselectEvent();

		/**
		* @brief  Ƕ���б�ؼ��ü��ã� ��������Ϊ��LIST ��POS �� SIZE
		* @n<b>��������</b>					: registerUnloadEvent
		* @n@param  int ��LIST ��POS.x
		* @param    int ��LIST ��POS.y
		* @param    int ��LIST ��SIZE.w
		* @param    int ��LIST ��SIZE.h
		* @remarks
		* @see		
		*/
		void SetParentListRect(int nX,int nY,int nW,int nH)
		{
			nParentX = nX*CC_CONTENT_SCALE_FACTOR();
			nParentY = nY*CC_CONTENT_SCALE_FACTOR();
			nParentW = nW*CC_CONTENT_SCALE_FACTOR();
			nParentH = nH*CC_CONTENT_SCALE_FACTOR();
		}


		/**
		* @brief ����б�ؼ����пؼ����¼���Ӧ����LIST �ؼ�����
		* @remarks
		* @see		
		*/
		void disableAllCtrlEvent();

		/**
		* @brief ��960*480 ��480*320 ��Ļ�ֱ����·�����ͬ��С
		* @remarks
		* @see		
		*/
		virtual CCSize getContentSize();



	public:
		virtual void onEnter(void);
		virtual void onExit(void);
		virtual void registerWithTouchDispatcher(void);
		virtual bool ccTouchBegan(CCTouch* touch, CCEvent* event);
		virtual void ccTouchEnded(CCTouch* touch, CCEvent* event);
		virtual void ccTouchCancelled(CCTouch *touch, CCEvent* event);
		virtual void ccTouchMoved(CCTouch* touch, CCEvent* event);
		virtual void destroy(void);
		virtual void keep(void);
		virtual void registerItemClickListener(ScutCxListItemClickListener *listener);

		
		virtual void unregisterItemClickListener(void);


		void triggerLoaderEvent(int nBegin,bool bForward);

#if 1
		virtual void registerItemClickListener(LUA_FUNCTION nSeletor);
#endif


		int  getParentX()
		{
			return nParentX;
		}
		int  getParentY()
		{
			return nParentY;
		}
		int  getParentW()
		{
			return nParentW;
		}
		int  getParentH()
		{
			return nParentH;
		}

		CCLayer* getInner_panel()
		{
			return inner_panel_;
		}

	protected:
		virtual void onItemClick(int index, ScutCxListItem *item) {}
		virtual void visit(void);



	private:
		ScutCxListItem *itemForTouch(CCTouch * touch);
		void doLayout(void);
		void doFitPos(float y_pos);

		CCRect rect(void)
		{
			CCSize s = getContentSize();
			//return CCRectMake(-s.width / 2, -s.height / 2, s.width, s.height);
			return CCRectMake(0, 0, s.width, s.height);
		}

		bool containsTouchLocation(CCTouch* touch);
	private:


		CScutListLoaderListener*		m_pLoaderListener;

		//�����ӽ���ʱ, ���ñ����Listview�Ƿ���Ż���
		bool m_bSilence;

		bool is_horizontal_mode;
		bool be_pageturn_effect;
		char recodeNumberPerPage;
		float touch_began_x_;
		float touch_ended_x_;
		float old_x_;
		float min_x_;
		float max_x_;
		float row_width_;

		int  nParentX;
		int  nParentY;
		int  nParentW;
		int  nParentH;

		ScutCxListItem *sel_item_;
		int		m_nSelectIndex;
		float row_height_;
		LIST_STATE list_state_;
		CCLayer *inner_panel_;
		float touch_began_y_;
		float touch_ended_y_;
		float old_y_;
		float min_y_;
		float max_y_;
		bool snap_flag_;
		LIST_SLIDE_DIR  slide_dir;
		//cc_timeval touch_began_time_;
		clock_t touch_began_time_;
		ccColor3B line_color_;
		ccColor3B sel_item_start_color_;
		ccColor3B sel_item_end_color_;

		int m_nScriptLoadFunc;
		int m_nScriptUnloadFunc;
		int m_nScriptUnselectFunc;


		ScutCxListItemClickListener *item_click_listener_;
#if 1
		int m_nScriptSeletor;
#endif

	};
}

#endif