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
#ifndef ScutLISTLOADERLISTERNER_HEADER
#define ScutLISTLOADERLISTERNER_HEADER

#include "ScutCxListItem.h"
using namespace ScutCxControl;

namespace ScutCxControl
{
		/**
		* @brief  list �ؼ�LOADER ������
		* @remarks   
		* @see		
		*/
	class CScutListLoaderListener{

	public :
		CScutListLoaderListener(){};
		virtual ~CScutListLoaderListener(){};

		 
		/**
		* @brief  list �ؼ�LOADER ������ �����ITEM ʱ LIST ���Щ�ӿ�
		* @n<b>��������</b>					: OnLoadItem
		* @n@param  int ��ǰҳ��
		* @remarks   
		* @see		
		*/
		virtual void OnLoadItem(int nCurPage)=0;//ScutCxListItem* pItem) = 0;
		/**
		* @brief  list �ؼ�LOADER ������ ��ж��ITEM ʱ LIST ���Щ�ӿ�
		* @n<b>��������</b>					: OnUnLoadItem
		* @n@param  int ��ǰҳ��
		* @remarks   
		* @see		
		*/
		virtual void OnUnLoadItem(int nCurPage)=0;//ScutCxListItem* pItem) = 0;

	};

}






#endif 