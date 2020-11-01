#include <iostream>
using namespace std;



void preposition(string p,string pt)
{

	if (pt=="implication")
	{
		if(p[0]!='~' && p[3]!='~')
		{
			cout<<"implication is: "<<p[0]<<"->"<<p[3]<<endl;
			cout<<"converse is: "<<p[3]<<"->"<<p[0]<<endl;
			cout<<"contrapositive is: "<<"~"<<p[3]<<"->~"<<p[0]<<endl;
			cout<<"inverse is: "<<"~"<<p[0]<<"->~"<<p[3];
		}
		else if(p[0]=='~' && p[4]!='~')
		{
			cout<<"implication is: "<<p[0]<<p[1]<<"->"<<p[4]<<endl;
			cout<<"converse is: "<<p[4]<<"->"<<p[0]<<p[1]<<endl;
			cout<<"contrapositive is: "<<"~"<<p[4]<<"->"<<p[1]<<endl;
			cout<<"inverse is: "<<p[1]<<"->~"<<p[4];
		}else if(p[0]!='~' && p[3]=='~')
		{
			cout<<"implication is: "<<p[0]<<"->"<<p[3]<<p[4]<<endl;
			cout<<"converse is: "<<p[3]<<p[4]<<"->"<<p[0]<<endl;
			cout<<"contrapositive is: "<<p[4]<<"->~"<<p[0]<<endl;
			cout<<"inverse is: "<<'~'<<p[0]<<"->"<<p[4];
		}else if(p[0]=='~' && p[4]=='~')
		{
			cout<<"implication is: "<<p[0]<<p[1]<<"->"<<p[4]<<p[5]<<endl;
			cout<<"converse is: "<<p[4]<<p[5]<<"->"<<p[0]<<p[1]<<endl;
			cout<<"contrapositive is: "<<p[5]<<"->"<<p[1]<<endl;
			cout<<"inverse is: "<<p[1]<<"->"<<p[5];
		}

	}else if(pt=="converse")
	{
		if(p[0]!='~' && p[3]!='~')
		{
			cout<<"converse is: "<<p[0]<<"->"<<p[3]<<endl;
			cout<<"implication is: "<<p[3]<<"->"<<p[0]<<endl;
			cout<<"contrapositive is: "<<"~"<<p[0]<<"->~"<<p[3]<<endl;
			cout<<"inverse is: "<<"~"<<p[3]<<"->~"<<p[0];
		}
		else if(p[0]=='~' && p[4]!='~')
		{
			cout<<"converse is: "<<p[0]<<p[1]<<"->"<<p[4]<<endl;
			cout<<"implication is: "<<p[4]<<"->"<<p[0]<<p[1]<<endl;
			cout<<"contrapositive is: "<<p[1]<<"->"<<"~"<<p[4]<<endl;
			cout<<"inverse is: "<<"~"<<p[4]<<"->"<<p[1];
		}else if(p[0]!='~' && p[3]=='~')
		{
			cout<<"converse is: "<<p[0]<<"->"<<p[3]<<p[4]<<endl;
			cout<<"implication is: "<<p[3]<<p[4]<<"->"<<p[0]<<endl;
			cout<<"contrapositive is: "<<"~"<<p[0]<<"->"<<p[4]<<endl;
			cout<<"inverse is: "<<p[4]<<"->~"<<p[0];
		}else if(p[0]=='~' && p[4]=='~')
		{
			cout<<"converse is: "<<p[0]<<p[1]<<"->"<<p[4]<<p[5]<<endl;
			cout<<"implication is: "<<p[4]<<p[5]<<"->"<<p[0]<<p[1]<<endl;
			cout<<"contrapositive is: "<<p[1]<<"->"<<p[5]<<endl;
			cout<<"inverse is: "<<p[5]<<"->"<<p[1];
		}

	}else if(pt=="contrapositive")
	{
		if(p[0]!='~' && p[3]!='~')
		{
			cout<<"contrapositive is: "<<p[0]<<"->"<<p[3]<<endl;
			cout<<"converse is: "<<"~"<<p[0]<<"->~"<<p[3]<<endl;
			cout<<"implication is: "<<"~"<<p[3]<<"->~"<<p[0]<<endl;
			cout<<"inverse is: "<<p[3]<<"->"<<p[0];
		}
		else if(p[0]=='~' && p[4]!='~')
		{
			cout<<"contrapositive is: "<<p[0]<<p[1]<<"->"<<p[4]<<endl;
			cout<<"converse is: "<<p[1]<<"->~"<<p[4]<<endl;
			cout<<"implication is: "<<"~"<<p[4]<<"->"<<p[1]<<endl;
			cout<<"inverse is: "<<p[4]<<"->~"<<p[1];
		}else if(p[0]!='~' && p[3]=='~')
		{
			cout<<"contrapositive is: "<<p[0]<<"->"<<p[3]<<p[4]<<endl;
			cout<<"converse is: "<<"~"<<p[0]<<"->"<<p[4]<<endl;
			cout<<"implication is: "<<p[4]<<"->~"<<p[0]<<endl;
			cout<<"inverse is: "<<p[3]<<p[4]<<"->"<<p[0];
		}else if(p[0]=='~' && p[4]=='~')
		{
			cout<<"contrapositive is: "<<p[0]<<p[1]<<"->"<<p[4]<<p[5]<<endl;
			cout<<"converse is: "<<p[1]<<"->"<<p[5]<<endl;
			cout<<"implication is: "<<p[5]<<"->"<<p[1]<<endl;
			cout<<"inverse is: "<<p[4]<<p[5]<<"->"<<p[0]<<p[1];
		}

	}else if(pt=="inverse")
	{
		if(p[0]!='~' && p[3]!='~')
		{
			cout<<"inverse is: "<<p[0]<<"->"<<p[3]<<endl;
			cout<<"implication is: "<<"~"<<p[0]<<"->~"<<p[3]<<endl;
			cout<<"converse is: "<<"~"<<p[3]<<"->~"<<p[0]<<endl;
			cout<<"contrapositive is: "<<p[3]<<"->"<<p[0];
		}
		else if(p[0]=='~' && p[4]!='~')
		{
			cout<<"inverse is: "<<p[0]<<p[1]<<"->"<<p[4]<<endl;
			cout<<"implication is: "<<p[1]<<"->~"<<p[4]<<endl;
			cout<<"converse is: "<<"~"<<p[4]<<"->"<<p[1]<<endl;
			cout<<"contrapositive is: "<<p[4]<<"->"<<p[0]<<p[1];
		}else if(p[0]!='~' && p[3]=='~')
		{
			cout<<"inverse is: "<<p[0]<<"->"<<p[3]<<p[4]<<endl;
			cout<<"implication is: "<<"~"<<p[0]<<"-              >"<<p[4]<<endl;
			cout<<"converse is: "<<p[4]<<"->~"<<p[0]<<endl;
			cout<<"contrapositive is: "<<p[3]<<p[4]<<"->"<<p[0];
		}else if(p[0]=='~' && p[4]=='~')
		{
			cout<<"inverse is: "<<p[0]<<p[1]<<"->"<<p[4]<<p[5]<<endl;
			cout<<"implication is: "<<p[1]<<"->"<<p[5]<<endl;
			cout<<"converse is: "<<p[5]<<"->"<<p[1]<<endl;
			cout<<"contrapositive is: "<<p[4]<<p[5]<<"->"<<p[0]<<p[1];
		}

	}
}


int main()
{
	string p,pt;

    cout<<"enter preposition type:-";
    cin>>pt;
    cout<<"enter preposition:-";
    cin>>p;
    preposition( p, pt);

}