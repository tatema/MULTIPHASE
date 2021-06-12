This is an H1
=======

This is an H2
---------

# this is H1
## this is H2
###### this is H6-


**这是加粗**
__这也是加粗__
*这是倾斜*
_这也是倾斜_
***这是加粗倾斜***
~~这是加删除线~~


1. 列表内容
2. 列表内容
3. 列表内容


8. Bird
1. McHale
4. Parish


<font face="黑体">我是黑体字</font>
<font face="微软雅黑">我是微软雅黑</font>
<font face="STCAIYUN">我是华文彩云</font>
<font color=red>我是红色</font>
<font color=#008000>我是绿色</font>
<font color=Blue>我是蓝色</font>
<font size=5>我是尺寸</font>
<font face="黑体" color=green size=5>我是黑体，绿色，尺寸为5</font>


$ X\stackrel{F}{\longrightarrow}Y $


*   This is a list item with two paragraphs.

    This is the second paragraph in the list item. You're
only required to indent the first line. Lorem ipsum dolor
sit amet, consectetuer adipiscing elit.

*   Another item in the same list.

- [前言](/)
- [目录](/guide)
- [技术栈选型](/?id=技术栈选型)
- [代码仓库](/?id=代码仓库)
- [用户体系](/src/account/?id=用户体系)
    + [账户服务](/src/account/?id=架构设计)
    + [权限服务](/src/account/?id=后台权限管理)
- [购物体系](/src/shopping/cart?id=购物体系)
    + [商品系统(Temporal万物)](/src/shopping/product?id=商品系统)
    + [购物车服务](/src/shopping/cart?id=购物车服务)
    + [购物车架构](/src/shopping/cart?id=购物车架构)
- [营销体系](/src/promotion/)
    + 活动营销系统
        * [通用抽奖工具(Glue万能胶)](/src/promotion/glue)
    + 销售营销系统
    + 基础服务
        * [秒杀服务](/src/promotion/seckill)
        * [优惠券服务](/src/promotion/coupon)
        * 积分服务
- [交易中心](/src/trade/)
    + [常见第三方支付流程](/src/trade/?id=常见第三方支付流程)
    + [支付系统设计](/src/trade/?id=支付系统设计)
    + 收银台
- [订单中心](/src/order/)
- [仓储系统](/src/warehouse/)
    + 地址服务
- [物流系统](/src/express/)
- [售后服务](/src/aftersale/)
- [基础服务](/src/base/)
    + 接口静态化服务
    + 上传服务
    + 消息服务
        * 短信
        * 邮件
        * 微信模板消息
        * 站内信




# Markdown Lab

This lab aims to easier the building of the markdown environment for slides, books, resume and articles.

![Markdown Lab Demo](images/markdown-lab-demo.jpg)

## Prepare

Please install docker at first:

* Linux, Mac OSX, Windows 10: [Docker CE](https://store.docker.com/search?type=edition&offering=community)
* Older Windows: [Docker Toolbox](https://www.docker.com/docker-toolbox)

Notes:

In order to run docker without password, please make sure your user is added in the docker group:

    $ sudo usermod -aG docker $USER

In order to speedup docker images downloading, please configure a local docker mirror in `/etc/default/docker`, for example:

    $ grep registry-mirror /etc/default/docker
    DOCKER_OPTS="$DOCKER_OPTS --registry-mirror=https://docker.mirrors.ustc.edu.cn"
    $ service docker restart

In order to avoid network ip address conflict, please try following changes and restart docker:

    $ grep bip /etc/default/docker
    DOCKER_OPTS="$DOCKER_OPTS --bip=10.66.0.10/16"
    $ service docker restart

If the above changes not work, try something as following:

    $ grep dockerd /lib/systemd/system/docker.service
    ExecStart=/usr/bin/dockerd -H fd:// --bip=10.66.0.10/16 --registry-mirror=https://docker.mirrors.ustc.edu.cn
    $ service docker restart

## Choose a working directory

If installed via Docker Toolbox, please enter into the `/mnt/sda1` directory of the `default` system on Virtualbox, otherwise, after poweroff, the data will be lost for the default `/root` directory is only mounted in DRAM.

    $ cd /mnt/sda1

For Linux or Mac OSX, please simply choose one directory in `~/Downloads` or `~/Documents`.

    $ cd ~/Documents

## Download

    $ git clone https://gitee.com/tinylab/cloud-lab.git
    $ cd cloud-lab/ && tools/docker/choose markdown-lab

## Installation

    $ tools/docker/build # Build ourselves
    or
    $ tools/docker/pull # Pull from docker hub

    $ tools/docker/run

Login the VNC page with the password printed in the console.

## Slides

    $ cd slides/
    $ make

To tune the theme and colortheme, based on `slides/doc/`, please configure
`latex_theme` and `latex_colortheme` in Makefile.

To specify the fonts, please open `templates/zh_template.tex` and configure the
`\set*font` commands with the fonts you want in the result of `fc-list`.

## Resume

    $ cd resume/
    $ make

If no gravatar.jpg specified, a gravatar will be added automatically if the
email address is there. To disable this feature, do:

    $ GRAVATAR_OPTION=--no-gravatar make

To specify the fonts, please open `templates/header.tex` and configure the
`\set*font` commands with the fonts you want in the result of `fc-list`.



## Article

    $ cd article/
    $ make

To specify the fonts, please open `templates/header.tex` and configure the
`\set*font` commands with the fonts you want in the result of `fc-list`.

## Book

    $ git submodule update --init book
    $ cd book/
    $ make

To specify the fonts, please open `book.jason` and configure the
`fontFamily` with the fonts you want in the result of `fc-list`.

## References

* [Markdown 基本语法](https://www.markdownguide.org/basic-syntax)
* [Pandoc's Markdown 语法](https://pandoc.org/MANUAL.html#pandocs-markdown)
