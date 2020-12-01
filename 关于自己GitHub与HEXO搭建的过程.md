title：首次GitHub×HEXO搭建

# 一、 搭建GitHub账号

## 0x01.注册自己的GitHub账号（注册时用的用户名和自己电脑的用户名一定要记清），并登录

## 0x02.创建仓库

1、单机右键，出现翻译成中文选项（如无，则跳过，英语好也可不用）
![在这里插入图片描述](https://img-blog.csdnimg.cn/20201130213358573.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3RydXRoX3lvdWxlYXZl,size_16,color_FFFFFF,t_70)

2、找到Repositories（仓库）旁的new（新建）并单击。

3、填写的仓库名为“用户名.github.io“，和左边的owner一定要保持一致！不然会导致出错。

## 0x03.启用GitHub Pages

1、点击<kbd>Settings</kbd>进入设置界面

2、往下拉找到“GitHub Pages”一栏，如果开启成功则会看到正常的显示（默认开启），如未开启则手动开启后再检查。


## 0x04.选择主题（可跳过，后面再设置）
1、点击<kbd>choose a theme</kbd>

2、选择喜欢的主题，然后点击<kbd>Select theme</kbd>



# 二、配置环境
## 0x01.下载安装*node.js*
1、搜索node.js,找到官网下载node.js.
官网链接: [link](https://nodejs.org/en/)

![在这里插入图片描述](https://img-blog.csdnimg.cn/20201130220551414.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3RydXRoX3lvdWxlYXZl,size_16,color_FFFFFF,t_70#pic_center)
2、根据安装说明，除路径选择之外一路默认（本人勾选了自动安装其余组件，不过无所谓），完成安装。

3、打开cmd命令窗口，分别输入`node -v`与`npm -v`，检测安装版本，如果为下图样式显示了版本，则为安装成功。

![在这里插入图片描述](https://img-blog.csdnimg.cn/20201130221637243.png#pic_center)

## 0x02.下载安装*Git*
1、搜索Git,找到官网下载Git.
官网链接: [link](https://git-scm.com/download/win)

![在这里插入图片描述](https://img-blog.csdnimg.cn/20201130223021891.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3RydXRoX3lvdWxlYXZl,size_16,color_FFFFFF,t_70#pic_center)
![在这里插入图片描述](https://img-blog.csdnimg.cn/20201130223039710.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3RydXRoX3lvdWxlYXZl,size_16,color_FFFFFF,t_70#pic_center)
2、还是一路默认，完成安装。安装完成后，在桌面单机右键，出现如下选项（具体出现哪个选项和安装时勾选的打开方式有关，如果是默认勾选则应为下图选项），说明安装成功。

![在这里插入图片描述](https://img-blog.csdnimg.cn/20201130223603361.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3RydXRoX3lvdWxlYXZl,size_16,color_FFFFFF,t_70#pic_center)


# 三、HEXO搭建


## 0x01.安装HEXO
1、在喜欢的地方创建一个文件夹，在文件夹下右击鼠标，选择<kbd>Git Bash here</kbd>（上文图中有）

2、输入`npm install -g hexo`进行安装（注意不要丢掉空格），然后用`hexo -v`检测安装，如果出现长串版本号，则说明安装成功

3、输入 `hexo init`初始化文件，可能要等待很长时间（看电脑更看脸🤔），最后显示"Start blogging with hexo!",说明初始化成功！

4、输入`nmp install`安装所需的组件

5、安装完成后输入`hexo g`，即开始hexo的使用之旅

6、输入`hexo s`，启动本地服务器，通过访问系统返回给你的网址正式体验HEXO(http://localhost:4000)


# 三、部署到GitHub
## 0x01.使用HEXO deploy部署到GitHub
1、编辑根目录下的_config.yml文件，添加如下代码（iPetrichor需替换为自己的用户名），保存更改后的文件
![在这里插入图片描述](https://img-blog.csdnimg.cn/20201201202701618.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3RydXRoX3lvdWxlYXZl,size_16,color_FFFFFF,t_70)
2、安装一个扩展——在目录下打开git bush界面，输入`npm install hexo-deployer-git --save`,如下图：![在这里插入图片描述](https://img-blog.csdnimg.cn/20201201203308920.png)

## 0x02.检查SSH Keys
1、输入`cd ~/.ssh`
2、输入`eval "$(ssh-agent -s)"`（注意空格的输入）
3、输入`ssh-add ~/.ssh/id_rsa`,之后会出现生成的*SSH Key*，后面要用
## 0x03.添加SSH Key到GitHub
1、点击<kbd>setting</kbd>进入设置界面

2、点击<kbd>SSH and GPG keys</kbd>,然后点击<kbd>New SSH key</kbd>新建SSH keys![在这里插入图片描述](https://img-blog.csdnimg.cn/20201201204317259.jpg?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3RydXRoX3lvdWxlYXZl,size_16,color_FFFFFF,t_70)
3、填写自己的key（title标题栏可随便填写）

4、输入`ssh -t git@github.com`，测试添加密钥是否成功，若Hi后面是自己的用户名，则说明成功



## 0x04.部署到github

1、输入`hexo d -g`,等待完成响应，然后使用"*用户名.github.io*",即可访问自己的博客。


