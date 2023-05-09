#第一个参数是文件目录filesdir 第二个参数是搜索的文本字符串searchstr
#如果未指定上述任何参数，则返回值 1 错误并打印语句退出 
#filesdir不是一个路径时uichu返回1
#打印一条消息“文件数为 X，匹配行数为 Y”，其中 X 是目录和所有子目录中的文件数，Y 是在文件中的行数

#!/bin/bash
#判断输入是否存在
if ! [ -z "$1" ] && ! [ -z "$2" ] ; then
	#echo "TRUE"
	:
else
	echo "ERROR: Missing parameter or invalid format"
	echo "INPUT: ./finder.sh {Path to search} {String to search}"
	exit 1
fi
#判断输入是否正确
if [ -d "$1" ] ; then
	:
else
	echo "ERROR: Path does not exist"
	exit 1
fi
#参数传递
directory=$1
string=$2
#查找字符串
X=$(grep -r -l $string $directory | wc -l)
Y=$(grep -r $string $directory | wc -l)

echo "The number of files are $X and the number of matching lines are $Y"
