@echo off

cd %cd%

set dbServer=.
set dbAcount=sa
set dbPass=123
set gameuser=game_user
set gamepass=123
set dbpath=%cd%\Data


@echo ���ò������£�
@echo     [dbServer] ���ݿ������:%dbServer%
@echo     [dbAcount] �ɴ������ݿ���ʺ�(sa):%dbAcount%
@echo     [dbPass]   �ɴ������ݿ������(sa):%dbPass%
@echo     [gameuser] ��Ϸ��¼�ʺ�:%gameuser%
@echo     [gamepass] ��Ϸ��¼����:%gamepass%
@echo     [dbpath] ���ݿ�洢·��:%dbpath%
@echo ================================================================

MD %dbpath%

Sqlcmd -? 2>nul 1>nul
if errorlevel 1 (
echo �밲װsqlcmd֧�֡�&pause>nul
exit
)

Sqlcmd -S %dbServer% -U %dbAcount% -P %dbPass% -d master -i ������ű�.sql -v gameuser="%gameuser%" dbpath="%dbpath%" 
@echo ���ڴ������ݿ�ɹ�!
@echo ���ڵ�������...
Sqlcmd -S %dbServer% -U %dbAcount% -P %dbPass% -d master -i ScutContractData.sql -v gameuser="%gameuser%" dbpath="%dbpath%"
@echo �������ݳɹ�!
@echo ִ�гɹ�
ECHO ���н�����& PAUSE
