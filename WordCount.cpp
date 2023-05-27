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
	string c="-c",w="-w";//-c�ַ��� -w������ -s������ -code������ -e�հ� -nע���� -h����	
if(argc==2||argc==1){
		return 0; 
	}else{
		
		if(argv[1]==c){
			printf("%ld���ַ�\n",count(argv[2]));
		}else if(argv[1]==w){
			printf("%ld����\n",word(argv[2]));
		}
	}
	return 0;
}

long count(string file){//���˿ո�ͻ��ж����ַ� 
	char c;
	long number=0;
	ifstream infile; 
    infile.open(file.data());//���ļ����������ļ��������� 
    assert(infile.is_open());//��ʧ��,�����������Ϣ,����ֹ�������� 
    while (!infile.eof())
    {
        infile>>c;
        number++;
    }
    if(number>=2) number--;
    infile.close();//�ر��ļ������� 
	return number;
}

long word(string file){//���˱�-�����Ķ��㵥�� 
	char c;
	long number=0;
	int temp=0;
	ifstream infile; 
    infile.open(file.data());//���ļ����������ļ��������� 
    assert(infile.is_open());//��ʧ��,�����������Ϣ,����ֹ�������� 
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
    infile.close();//�ر��ļ������� 
	return number;
}

