// TestWCService.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

#include "SoapBinding.nsmap"
#include "soapSoapBindingProxy.h"

int main()
{
    SoapBindingProxy proxy;// = new SoapBindingProxy();
    std::string strurl = "http://wc11.qdthinker.com/Windchill/servlet/RPC?CLASS=com.infoengine.soap";
    proxy.soap_endpoint = strurl.c_str();
    proxy.soap->userid = "user001";
    proxy.soap->passwd = "1";

    std::string strcol;
    int ix = proxy.findModelByName("test",strcol);
    std::cout << "findModelByName: " << ix << " " << strcol << std::endl;
    //soap_dom_element* rootNode = soap_dom_parser(strcol.c_str(), strcol.size());
    //soap_dom_element* stringValueNode = rootNode->child(); // Assuming the string value is the first child element
    //std::string stringValue = stringValueNode->get_text();
  //  SoapBindingService* proxy2 = new SoapBindingService();

    std::cout << "Hello World!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
