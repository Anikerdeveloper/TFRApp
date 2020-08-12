#pragma once

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class TFR
{
private:
	bool HasTheDesiredAttribute(string AttributeName);
	string GetAttributeValue(string AttributeName);//Значение атрибута
public:
	void TFRFile(string File);//Получение ссылки на файл
	string GetTagFromLine();//Получение тэга строки (больше для работы системы)
	int TagCount(string Tag);//Количество тэгов в файле
	string ReadFromTag(string Tag); //Получение одиночной строки по тэгу
	string GetMultiLine(string TagName); //Получение многострочного текста по тэгу
	string GetLineOfAttribute(string Tag, string AttributeName, string AttributeValue); //Получение строки с нужным тэгом, атрибутом, значением атрибута

};

