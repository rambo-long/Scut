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
#ifndef __SCUTCX_LIST_ITEM_H_
#define __SCUTCX_LIST_ITEM_H_

#include "ControlDefine.h"
#include "cocos2d.h"
#include <map>
#include <list>
using namespace cocos2d;

namespace ScutCxControl {

#define ScutCxListItemChild CCNode

	/**
	* @brief  ����ؼ�����
	* @remarks   
	* @see		
	*/
	class LUA_DLL ScutCxListItem : public CCLayerColor
	{
		friend class ScutCxList;
	protected:
		ScutCxListItem(void);
		virtual ~ScutCxListItem(void);

	public:
		static ScutCxListItem *itemWithColor(const ccColor3B &color);

		/**
		* @brief  ��ȡ�ؼ������RECT
		* @n<b>��������</b>					: rect
		* @remarks
		* @see		
		*/
		CCRect rect(void);

		/**
		* @brief  ��ؼ�����Ϊѡ��״̬
		* @n<b>��������</b>					: selected
		* @remarks
		* @see		
		*/
		void selected(void);
		/**
		* @brief  ��ؼ�����Ϊ��ѡ��״̬
		* @n<b>��������</b>					: unselected
		* @remarks
		* @see		
		*/
		void unselected(void);
		/**
		* @brief  ��ؼ�����Ϊ��ѡ��״̬
		* @n<b>��������</b>					: unselected
		* @remarks
		* @see		
		*/
		void setItemColor(const ccColor3B &color);
		/**
		* @brief  ��ؼ�����ı߿�
		* @n<b>��������</b>					: setMargin
		* @remarks
		* @see		
		*/
		void setMargin(CCSize margin);
		/**
		* @brief  ��ȡ�ؼ�����ı߿�
		* @n<b>��������</b>					: getMargin
		* @remarks
		* @see		
		*/
		CCSize getMargin(void);

	public:

		/**
		* @brief  ADD �ؼ����б�ؼ�������  ����Ĭ�ϲ���,�� 0,0 ��Ϊ����
		* @n<b>��������</b>					: addChildItem
		* @n@param  child �ؼ�ָ��
		* @remarks
		* @see		
		*/
		void addChildItem(CCNode *child);

		/**
		* @brief  ADD �ؼ����б�ؼ�������
		* @n<b>��������</b>					: addChildItem
		* @n@param  child �ؼ�ָ��
		* @param    LayoutParam ����
		* @remarks
		* @see		
		*/
		void addChildItem(CCNode *child, const LayoutParam &layout);

		/**
		* @brief  ADD�ӿؼ����б�ؼ������ϣ��������б�ؼ����ӹܿؼ����¼� 
		* @n<b>��������</b>					: addChildItem
		* @n@param  child �ؼ�ָ��
		* @param    LayoutParam ����
		* @param    int ��LIST ��SIZE.w
		* @param    int tag==1  ��˵���ӽ����Ŀؼ���Ҫ��LIST ���ӹ��¼��ַ�
		* @remarks  �ӿؼ�����TOUCH �¼�ʱ ������TAG ֵΪ1 ��
		* @see		
		*/
		void addChildItem(CCNode *child, const LayoutParam &layout, int tag );



		/**
		* @brief  ͨ��TAG ��ȡ�б�ؼ�����
		* @n<b>��������</b>					: getChildByTag
		* @n@param  int �ؼ���tagֵ
		* @see		
		*/
		ScutCxListItemChild *getChildByTag(int tag);


		/**
		* @brief  ���б�ؼ����������滭�� 
		* @n<b>��������</b>					: setDrawTopLine
		* @n@param  bool �Ƿ���
		* @remarks  Ĭ��ΪFALSE ��
		* @see		
		*/
		void setDrawTopLine(bool value) { draw_top_line_ = value; }
		/**
		* @brief  ���б�ؼ����������滭�� 
		* @n<b>��������</b>					: setDrawBottomLine
		* @n@param  bool �Ƿ���
		* @remarks  Ĭ��ΪFALSE ��
		* @see		
		*/
		void setDrawBottomLine(bool value) { draw_bottom_line_ = value; }

		/**
		* @brief  �Ƿ��б�ؼ�����ѡ��ʱ�ĵ�ɫ
		* @n<b>��������</b>					: setDrawBottomLine
		* @n@param  bool �Ƿ���
		* @remarks  Ĭ��ΪFALSE ��
		* @see		
		*/
		void setDrawSelected(bool value) { draw_selected = value; }

		/**
		* @brief  �Կؼ����в����������� 
		* @n<b>��������</b>					: requestLayout
		* @n@param  void  
		* @remarks  �Կؼ����в�����������  ��
		* @see		
		*/
		void requestLayout(void);

		/**
		* @brief  �����б�ؼ����¼��ַ� 
		* @remarks   
		* @see		
		*/
		void registerWithTouchDispatcher();
		virtual bool ccTouchBegan(CCTouch* touch, CCEvent* event);
		virtual void ccTouchEnded(CCTouch* touch, CCEvent* event);
		virtual void ccTouchCancelled(CCTouch *touch, CCEvent* event);
		virtual void ccTouchMoved(CCTouch* touch, CCEvent* event);

		virtual void MyTouchDispatcher(CCNode* pParent, int nToutchEvent, CCTouch* touch, CCEvent* event);


		/**
		* @brief  onEnter�¼�
		* @n<b>��������</b>					: onEnter
		* @see		
		*/
		virtual void onEnter(void);


		/**
		* @brief  onExit�¼�
		* @n<b>��������</b>					: onEnter
		* @see		
		*/
		virtual void onExit(void);

		/**
		* @brief  ��̬���Ƿ���Ӧ�¼� 
		* @n<b>��������</b>					: SetSilence
		* @n@param  bool  �Ƿ���Ӧ�¼�
		* @remarks  ʹ�����ӣ� �����ӽ���ʱ, ���ñ����Listview�Ƿ���Ż��� ��
		* @see		
		*/
		void SetSilence(bool bSilence)
		{
			m_bSilence = bSilence;
		}

		bool getIsItemCatch()
		{
			return m_bCatchEndNode;
		}
		void setIsItemCatch(bool bCatch)
		{
			m_bCatchEndNode = bCatch;
		}


	protected:
		bool initWithWidthHeight(GLfloat width, GLfloat height);

		void setLineColor(const ccColor3B &color);
		void setSelectedColor(const ccColor3B &start_color, const ccColor3B &end_color);
		void updateColor(void);


		bool containsTouchLocation(CCTouch* touch)
		{	 
			return rect().containsPoint(convertTouchToNodeSpaceAR(touch));
		}

		virtual void draw(void);

		void disableCtrlEvent();
		void disableCtrlChildEvent(CCNode* pParent);

		void clear();

		bool findInDeque(CCNode* node);
		bool findInTouchEventLayerDeque(CCNode* node);

	private:
		bool selected_;
		ccColor3B line_color_;
		ccColor3B sel_item_start_color_;
		ccColor3B sel_item_end_color_;
		bool draw_top_line_;
		bool draw_bottom_line_;
		bool draw_selected;
		std::map<CCNode *, LayoutParam> layout_info_;
		float horizontal_margin_;
		float vertical_margin_;

		//�����ӽ���ʱ, ���ñ����Listview�Ƿ���Ż���
		bool m_bSilence;

		typedef std::vector<CCLayer*> TOUCHBEGAN_VEC;
		TOUCHBEGAN_VEC	m_pVectorTouchBegan;

		//��¼����LIST ʱ���д��¼��Ĳ�
		TOUCHBEGAN_VEC	m_pVectorTouchEventLayer;

		bool m_bCatchEndNode;


	};

}

#endif