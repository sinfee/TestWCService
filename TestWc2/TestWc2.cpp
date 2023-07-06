// TestWc2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
//#include "../tp/SoapBinding.nsmap"
//#include "../tp/soapSoapBindingProxy.h"

#include "../tp2/SoapBinding.nsmap"
#include "../tp2/soapH.h"
//#include "../tp2/dom.h"

void print_dom(struct soap_dom_element* elem) {
    if (elem->name) {
        std::cout << "Node name: " << elem->name << std::endl;
        if (std::string(elem->name) == "result" && elem->text) {
            std::cout << "Result text: " << elem->text << std::endl;
        }
    }

    for (struct soap_dom_element* child = elem->elts; child; child = child->next) {
        print_dom(child);
    }
}

int main()
{
 //   SoapBindingProxy proxy;// = new SoapBindingProxy();
 //   std::string strurl = "http://wc11.qdthinker.com/Windchill/servlet/RPC?CLASS=com.infoengine.soap";
 //   proxy.soap_endpoint = strurl.c_str();
 //   proxy.soap->userid = "user001";
 //   proxy.soap->passwd = "1";

 //   std::string strcol;
 //   int ix = proxy.findModelByName("test", strcol);
 //   if (ix != SOAP_OK)
 //   {
	//	std::cout << "findModelByName: " << ix << " " << strcol << std::endl;
	//	return 0;
	//}
 // 
 //   std::cout << "findModelByName: " << ix << " " << strcol << std::endl;

    soap client_socket;
    soap_init(&client_socket);
    
    client_socket.mode = SOAP_C_UTFSTRING;
    client_socket.userid = "user001";
    client_socket.passwd ="1";

    const char* strurl = "http://wc11.qdthinker.com/Windchill/servlet/RPC?CLASS=com.infoengine.soap";
    std::string strcol;
    int ix = soap_call_ns1__findModelByName(&client_socket, strurl, "", "test", strcol);

    if (client_socket.error)
    {
        std::cout << "SOAP error: " << client_socket.error << " " << soap_faultstring(&client_socket) << std::endl;
    }
    else
    {
        std::cout << "findModelByName: " << ix << " " << strcol << std::endl;
    }

    soap_destroy(&client_socket);
    soap_end(&client_socket);
   // soap_free(&client_socket);

    //std::string xml_string = strcol; // 你接收到的XML字符串

    //struct soap dom_soap;
    //soap_init(&dom_soap);
    //dom_soap.recv_timeout = 10; // 设置超时（可选）
    //dom_soap.send_timeout = 10; // 设置超时（可选）

    //struct soap_dom_element dom(&dom_soap, NULL, 0, NULL, NULL, NULL);

    //if (soap_dom_parser(&dom_soap, &dom, xml_string.c_str(), xml_string.size())) {
    //    soap_stream_fault(&dom_soap, std::cerr);
    //    return -1;
    //}

    //// 遍历DOM并打印节点名称和文本内容
    //print_dom(&dom);

    //soap_destroy(&dom_soap);
    //soap_end(&dom_soap);
    //soap_done(&dom_soap);



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
