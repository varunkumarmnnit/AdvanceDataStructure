#include "Graph.h"
#include "Routing.h"
#include<cstring>
#include<fstream>

//Converts any integer into binary value 
string Binary(int num)
{
	string tmp;
	for(int i=0;i<8;i++)
	{
		tmp=to_string((num&1))+tmp;
		num=num>>1;
	}
	return tmp;
}
/*
This function convert the IP ADRESS into binary format 
*/
string ConvertToBinary(string line)
{

	string res;
	char *tmp=strtok(&line[0],".");//Extract the value from Ip with '.' deliminator
	while(tmp!=NULL)
	{
		res=res+Binary(stoi(tmp));
		tmp=strtok(NULL,".");

	}

	return res;
}
int main(int argc,char *argv[])
{
	vector<string>Iptmp;
	if(argc!=5)
	{
		cout<<"wrong no of arguments"<<endl;
		return 0;
	}
	Graph g(argv[1]); //Creation of graph from from input graph file 
	ifstream inIp;
	string line;
	inIp.open(argv[2]); // Adding IP address in vector from the given IP mapping file 
	while(getline(inIp,line))
	{
		Iptmp.push_back(ConvertToBinary(line));
	}
	inIp.close();
	g.Ip=Iptmp;
//    cout<<endl<<g.Ip[0]<<endl<<g.Ip[1]<<endl<<g.Ip[2]<<endl;
    //int s=1,d=6;
	routing_table(&g,stoi(argv[3]),stoi(argv[4]));

return 0;

}
