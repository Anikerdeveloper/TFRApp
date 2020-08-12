#include "TFR.h"

string FileLink = "";
string Buff;

bool TFR::HasTheDesiredAttribute(string AttributeName) {
    string Attribute = "";
    bool HasOrNot = false;
    for (int i = 1; i < Buff.length(); i++)
    {
        if (Buff[i] != ' ' && Buff[i] != '>' && Buff[i] != '=')
        {
            Attribute += Buff[i];
        }
        else if (Buff[i] == '=' && Attribute == AttributeName)
        {
            HasOrNot = true;
            break;
        }
        else if (Buff[i] == ' ')
        {
            Attribute = "";
        }
        else if (Buff[i] == '>')
        {
            break;
        }
    }
    return HasOrNot;
}

string TFR::GetAttributeValue(string AttributeName) { //�������� ��������
    string Attribute = "";
    string AttributeV = "";
    int BuffL = Buff.length();
    for (int i = 1; i < BuffL; i++)
    {
        if (Buff[i] != ' ' && Buff[i] != '>' && Buff[i] != '=')
        {
            Attribute += Buff[i];
        }
        else if (Buff[i] == '=' && Attribute == AttributeName)
        {
            for (int j = i + 1; j < BuffL; j++)
            {
                if (Buff[j] != ' ' && Buff[j] != '>') {
                    AttributeV += Buff[j];
                }
                else {
                    break;
                }
            }
            break;
        }
        else if (Buff[i] == ' ')
        {
            Attribute = "";
        }
        else if (Buff[i] == '>')
        {
            break;
        }
    }
    return AttributeV;
}

void TFR::TFRFile(string File) { //��������� ������ �� ����
    FileLink = File;
}

string TFR::GetTagFromLine() { //��������� ���� ������ (������ ��� ������ �������)
    string TagInLine = "";
    if (Buff[0] == '<') {
        for (int i = 1; i < Buff.length(); i++)
        {
            if (Buff[i] != '>' && Buff[i] != ' ')
            {
                TagInLine += Buff[i];
            }
            else {
                break;
            }
        }
    }
    return TagInLine;
}



int TFR::TagCount(string Tag) { //���������� ����� � �����
    string LBuff;
    string TagInLine = "";
    int Count = 0;
    ifstream ofile(FileLink);
    if (ofile.is_open()) {
        while (!ofile.eof())
        {
            getline(ofile, Buff, '\n');
            if (Tag == GetTagFromLine())
            {
                Count++;
            }
        }
        return Count;
    }
}


string TFR::ReadFromTag(string Tag) { //��������� ��������� ������ �� ����
    string TextInLine;
    int BuffL = 0;
    ifstream ofile(FileLink);
    if (ofile.is_open()) {
        while (!ofile.eof())
        {
            getline(ofile, Buff, '\n');
            BuffL = Buff.length();
            for (int i = 0; i < BuffL; i++)
            {
                if (Buff[0] != '<') {
                    TextInLine += '\n' + Buff;
                    //cout << "��������! �������� ��������� �����! ���������� ������ �� ��������������� �����������!" << endl;
                    break;
                }
                else if (Buff[i] == '>' && Tag == GetTagFromLine()) {
                    for (int j = i + 1; j < BuffL; j++)
                    {
                        TextInLine += Buff[j];
                    }
                    ofile.close();
                    return TextInLine;
                }
            }
        }
    }
}


string TFR::GetMultiLine(string TagName) { //��������� �������������� ������ �� ����
    string TextInLine;
    int BuffL = 0;
    ifstream ofile(FileLink);

    if (ofile.is_open()) {
        while (!ofile.eof())
        {
            getline(ofile, Buff, '\n');
            BuffL = Buff.length();
            if (Buff[0] == '<')
            {
                for (int i = 1; i < BuffL; i++)
                {
                    if (Buff[i] == '>' && TagName == GetTagFromLine()) {
                        for (int j = i + 1; j < BuffL; j++)
                        {
                            TextInLine += Buff[j];
                        }
                        break;
                    }
                }
            }
            else {
                TextInLine += '\n' + Buff;
            }
        }
        return TextInLine;
    }
}

string TFR::GetLineOfAttribute(string Tag, string AttributeName, string AttributeValue) { //��������� ������ � ������ �����, ���������, ��������� ��������
    string AttributeN = "";
    string AttributeV = "";
    string TextInLine;
    int BuffL = 0;
    ifstream ofile(FileLink);
    if (ofile.is_open()) {
        while (!ofile.eof())
        {
            getline(ofile, Buff, '\n');
            BuffL = Buff.length();
            if (Tag == GetTagFromLine() && HasTheDesiredAttribute(AttributeName) && AttributeValue == GetAttributeValue(AttributeName))
            {
                for (int i = 0; i < BuffL; i++)
                {
                    if (Buff[i] == '>') {
                        for (int j = i + 1; j < BuffL; j++)
                        {
                            TextInLine += Buff[j];
                        }
                        break;
                    }
                }
                break;
            }
        }
    }
    return TextInLine;
}
