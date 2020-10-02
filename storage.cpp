#include <iostream>
using namespace std;
class Storage
{
protected:
	char name[25];
	char type[15];
public:
	Storage(){}
};
class Flash:protected Storage
{
private:
	int memory_amount;
	int memory_left;
	int memory_under_file;
	int speed_USB_3;
public:
	Flash()
	{
		cout<<"\n  Flash"<<endl;
		cout<<"\n  Name of device : ";
		flushall();
		cin.getline(name,25);
		cout<<"  Type : ";
		flushall();
		cin.getline(type,15);
		cout<<"  Amount of memory : ";
		cin>>memory_amount;
		memory_left=memory_amount;
	    memory_under_file=0;
		speed_USB_3=5000;// Ìáàéò/c
	}
	void get_memory_amount()
	{cout<<"\n  Amount of memory on "<<name<<" = "<<memory_amount<<endl;}
	void get_memory_left()
	{cout<<"\n  Amount of memory which left on "<<name<<" = "<<memory_left<<endl;}
	int info_copy(int info_size)
	{
		memory_under_file+=info_size;
		if (memory_under_file>memory_amount)
		{
			memory_left=0;
			memory_under_file=memory_amount;
			return info_size-memory_amount;
		}
		return 0;
	}
	float time_to_copy()
	{return memory_under_file/speed_USB_3;}
};
class DVD:protected Storage
{
private:
	int memory_amount;
	int memory_left;
	int memory_under_file;
	int writing_speed,reading_speed;
public:
	DVD()
	{
		cout<<"\n  DVD"<<endl;
		cout<<"\n  Name of device : ";
		flushall();
		cin.getline(name,25);
		cout<<"  Type : ";
		flushall();
		cin.getline(type,15);
		if (stricmp(type,"unilateral")==0)
			memory_amount=4700;//Ìáàéò
		else if (stricmp(type,"bilateral")==0)
			memory_amount=9000;//Ìáàéò
		memory_left=memory_amount;
		memory_under_file=0;
		reading_speed=21;//Ìáàéò/c
		writing_speed=21;//Ìáàéò/c
	}
	void get_memory_amount()
	{cout<<"\n  Amount of memory on "<<name<<" = "<<memory_amount<<endl;}
	void get_memory_left()
	{cout<<"\n  Amount of memory which left on "<<name<<" = "<<memory_left<<endl;}
	int info_copy(int info_size)
	{
		memory_under_file+=info_size;
		if (memory_under_file>memory_amount)
		{
			memory_left=0;
			memory_under_file=memory_amount;
			return info_size-memory_amount;
		}
		return 0;
	}
	float time_to_copy()
	{return memory_under_file/writing_speed;}
};
class HDD:protected Storage
{
private:
	int memory_amount;
	int memory_left;
	int memory_under_file;
	int speed_USB_2;
public:
	HDD()
	{
		cout<<"\n  HDD"<<endl;
		cout<<"\n  Name of device : ";
		flushall();
		cin.getline(name,25);
		cout<<"  Type : ";
		flushall();
		cin.getline(type,15);
		cout<<"  Amount of memory : ";
		cin>>memory_amount;
		memory_left=memory_amount;
		memory_under_file=0;
		speed_USB_2=600;//Ìáàéò/c
	}
	void get_memory_amount()
	{cout<<"\n  Amount of memory on "<<name<<" = "<<memory_amount<<endl;}
	void get_memory_left()
	{cout<<"\n  Amount of memory which left on "<<name<<" = "<<memory_left<<endl;}
	int info_copy(int info_size)
	{
		memory_under_file+=info_size;
		if (memory_under_file>memory_amount)
		{
			memory_left=0;
			memory_under_file=memory_amount;
			return info_size-memory_amount;
		}
		return 0;
	}
	float time_to_copy()
	{return memory_under_file/speed_USB_2;}
};
bool info_copy(Flash F,DVD D,HDD H)
{
	int memory,left;
	cout<<"\n  Memory to copy (MB) : ";
	cin>>memory;
	left=F.info_copy(memory);
	if (left>0)
	{
		left=D.info_copy(left);
		if (left>0)
			left=H.info_copy(left);
		else
			return 0;
	}
	else
		return 0;
}
int main()
{
	Storage S;
	Flash F;
	DVD D;
	HDD H;
	info_copy(F,D,H);
	float time;
	time=F.time_to_copy();
	time+=D.time_to_copy();
	time+=H.time_to_copy();
	cout<<"\n  Time for copying : "<<time<<endl;
	return 0;
}