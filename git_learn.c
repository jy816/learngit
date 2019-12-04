工作区和暂存区
	工作区：电脑里能看到的目录
	暂存区：git add命令实际上就是把要提交的所有修改放到暂存区
	git commit就可以一次性把暂存区的所有修改提交到分支
一、基本操作
1.1创建版本库
	1. mkdir learngit  					创建空目录
	   cd learngit
	2. git init        					把这个目录变成Git可以管理的仓库
1.2把一个文件放到Git仓库
	1. git add readme.txt
	2. git commit -m "wrote a readme file"   -m后面输入的是本次提交的说明，可以输入任意内容
	add 可添加多个文件，把文件先放在暂存区，之后commit统一提交
	使用it commit之前必须先使用git add
1.3版本回退（已提交到版本库）
	1. git log                   		显示当前分支的版本历史记录    --pretty=oneline输出简要信息
	2. git reset --hard 版本号			HEAD指针指向当前版本，HEAD^指向上一版本 ^^上上
	3. git reflog						查看命令历史，寻找版本号
1.4撤销修改
	1. git checkout -- file 			改乱了工作区某个文件的内容，想直接丢弃工作区的修改时    
	2. 不但改乱了工作区某个文件的内容，还添加到了暂存区时，想丢弃修改，分两步，第一步用命令git reset HEAD <file>，就回到了1，第二步按1操作
	3. 已经提交了不合适的修改到版本库时，使用版本回退
1.5删除文件
	1. git rm 
	   git commit
	2. git reset --hard 版本号			误删，恢复			 

二、分支管理 
2.1创建与合并分支
	1. 查看分支：git branch
	2. 创建分支：git branch <name>
	3. 切换分支：git checkout <name>或者git switch <name>
	4. 创建+切换分支：git checkout -b <name>或者git switch -c <name>
	5. 合并某分支到当前分支：git merge <name>
	6. 未合并分支：删除分支 git branch -d <name>   强制删除 git branch -D <name> 
	7. 两个分支都对文件进行修改，合并时候冲突。把冲突部分删除，重新合并
2.2Bug分支
	1. git stash 		    保护现场
	2. git stash list		显示stash的所有变更，查看stash号
	3. git stash pop		恢复的同时把stash内容也删了（最近一次）
	4. git stash apply +stash号 恢复现场     
	5. git stash drop +stash号  删除stash
	6. git cherry-pick <commit>   复制一个特定的提交到当前分支，几个分支有相同BUG，在一个分支上改完可以提交到当前分支，不需重复修改
2.3多人协作
	1. git remote											查看远程库的信息   -v详细信息
	2. git push origin branch-name      					把本地内容推送到远程分支
	3. git checkout -b branch-name origin/branch-name   	想在本地其他分支上开发，在本地创建和远程分支对应的分支
	   创建之后，进行开发，经常push，push失败，先用git pull抓取远程的新提交
	   (1)git pull失败，git branch --set-upstream branch-name origin/branch-name建立本地分支和远程分支的关联
	   (2)git pull成功，如果有冲突，要先处理冲突
三、Github
3.1远程仓库
	1. github创建一个仓库，和本地仓库名字相同
	2. git remote add origin git@github.com:username/repo-name.git   关联远程库
	3. git push -u origin master									 关联后，使用命令第一次推送master分支的所有内容  -u 第一次提交
	4. git push origin master
3.2从远程库克隆
	   git clone git@github.com:name/gitskills.git
3.3	
	在GitHub上，可以任意Fork开源仓库；
	自己拥有Fork后的仓库的读写权限；
	可以推送pull request给官方仓库来贡献代码




























