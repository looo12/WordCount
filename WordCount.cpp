#include "stdlib.h"
#include "stdio.h"
#include <iostream>
#include <string>
#include <fstream>
#include <assert.h>
using namespace std;

long count(string file);
long word(string file);
int main(int argc,char *argv[])
{
	string c="-c",w="-w";//-c字符数 -w单词数 -s句子数 -code代码行 -e空白 -n注释行 -h帮助	
if(argc==2||argc==1){
		return 0; 
	}else{
		
		if(argv[1]==c){
			printf("%ld个字符\n",count(argv[2]));
		}else if(argv[1]==w){
			printf("%ld单词\n",word(argv[2]));
		}
	}
	return 0;
}

long count(string file){//除了空格和换行都算字符 
	char c;
	long number=0;
	ifstream infile; 
    infile.open(file.data());//将文件流对象与文件连接起来 
    assert(infile.is_open());//若失败,则输出错误消息,并终止程序运行 
    while (!infile.eof())
    {
        infile>>c;
        number++;
    }
    if(number>=2) number--;
    infile.close();//关闭文件输入流 
	return number;
}

long word(string file){//除了被-隔开的都算单词 
	char c;
	long number=0;
	int temp=0;
	ifstream infile; 
    infile.open(file.data());//将文件流对象与文件连接起来 
    assert(infile.is_open());//若失败,则输出错误消息,并终止程序运行 
    infile >> noskipws;
    while (!infile.eof())
    {
        infile>>c;
        if(65<=c&&c<=122&&temp==0){
        	temp++;
		}
		if(temp!=0&&c<65&&c!=45){
			number++;
			temp=0;
		}
		if(temp!=0&&c>122){
			number++;
			temp=0;
		}
    }
    if(temp!=0) number++;
    infile.close();//关闭文件输入流 
	return number;
}

