------------------------------------------------------------------
--LoginScene.lua
-- Author     : JMChen
-- Version    : 1.0.0.0
-- Date       : 2011-10-15
-- DescriCCPointion����½���� 
------------------------------------------------------------------


module("LoginScene", package.seeall)




-- �������õ��ĳ�Ա����Ҫ���ļ�ͷ���������������ӱ�Ҫ��˵��
-- ��Ա����ͳһ���»��߿�ʼ�����ӵ�����ĸҪСд
 
local mScene = nil 		-- ����
local mLayer = nil 		-- ��

--
---------------���нӿ�(�������������̶����øı�)--------
--


-- �˳�����
function closeScene()
	releaseResource()
end

--
-------------------------˽�нӿ�------------------------
--
-- ��ʼ����Դ����Ա����
function initResource()

end



-- �ͷ���Դ
function releaseResource()
	mScene=nil
	mLayer=nil
end

-- ��������
function init(type)
--ע�������push�ص�
	initResource()

	-- ע������ص�
	local scene = ScutScene:new()	
	scene:registerCallback(netCallback)	
	mScene = scene.root;	
	mLayer = CCLayer:create()
	mLayer:setAnchorPoint(CCPoint(0,0))
	mLayer:setPosition(CCPoint(0,0))
	mScene:addChild(mLayer, 0)
	
	CCDirector:sharedDirector():pushScene(mScene)
	CCDirector:sharedDirector():RegisterBackHandler("MainScene.closeApp")
	
	m_CurrentType=type
	if isFirstLogin==nil then
		isFirstLogin=true
	end;
	

    local spriteNor = CCSprite:create(P("button/button_1013.png"))
    local spriteDown = CCSprite:create(P("button/button_1013.png")) 
    spriteDown:setScale(0.94)
    
    local label = CCLabelTTF:create("send", FONT_NAME,FONT_SM_SIZE); 
    label:setPosition(CCPoint(spriteNor:getContentSize().width / 2, spriteNor:getContentSize().height / 2))
    spriteNor:addChild(label, 0)  
    
    local label = CCLabelTTF:create("send", FONT_NAME,FONT_SM_SIZE); 
    label:setPosition(CCPoint(spriteNor:getContentSize().width / 2, spriteNor:getContentSize().height / 2))
    spriteDown:addChild(label, 0) 
    
    spriteDown:setPosition(CCPoint(spriteNor:getContentSize().width * 0.03, spriteNor:getContentSize().height * 0.03))
    local menuItem = CCMenuItemSprite:create(spriteNor, spriteDown)
    local menu = CCMenu:createWithItem(menuItem)
    menu:setContentSize(menuItem:getContentSize())
    menu:setAnchorPoint(CCPoint(0, 0))
    mLayer:addChild(menu,0)
    menu:setPosition(PT(pWinSize.width/2,pWinSize.height*0.2))
    menuItem:registerScriptTapHandler(LoginScene.callAction)
    
    

end


function callAction()
   	ZyWriter:writeString("ActionId",100)
	local lenth=string.len(ZyWriter:generatePostData())
	local addressPath=("127.0.0.1:9001")
	ScutDataLogic.CDataRequest:Instance():AsyncExecTcpRequest(mScene,addressPath, 1, nil, ZyWriter:generatePostData(), lenth);
	ScutDataLogic.CNetWriter:resetData();		
	ScutDataLogic.CNetWriter:resetData() 	
end


---����ص�
function netCallback(pScutScene, lpExternalData)
	local actionId = ZyReader:getActionID();
	local userData = ZyRequestParam:getParamData(lpExternalData)
    if actionId ==100 then
        local content=ZyReader:readString();
        local label=CCLabelTTF:create(content,FONT_NAME,FONT_SM_SIZE); 
        mScene:addChild(label,1)
        label:setPosition(CCPoint(pWinSize.width/2,pWinSize.height/2))   
        local secondAction = CCSequence:createWithTwoActions(CCFadeOut:create(0.55),
        CCCallFuncN:create(LoginScene.hide))
        local  action = CCSequence:createWithTwoActions(CCDelayTime:create(1),secondAction)
        label:runAction(action)   
    end
end


ZyWriter = ScutDataLogic.CNetWriter:getInstance()
ZyReader = ScutDataLogic.CNetReader:getInstance()
ZyRequestParam = {param = {}}
function ZyRequestParam:getParamData(nTag)
	return ZyRequestParam.param[nTag]
end

function ZyReader.readString()
	local nLen = ZyReader:getInt()
	local strRet = nil
	if nLen ~= 0
	then
        local str = ScutDataLogic.CLuaString:new("")
        ZyReader:getString(str, nLen)
        strRet = string.format("%s", str:getCString())
        str:delete()
	end
	return strRet
end

function hide(node)
	if node~= nil then
	    node:getParent():removeChild(node, true)
	    node=nil
	end
end