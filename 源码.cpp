
//�������ù����γ̣�Ȼ���Ǹ���ѡ�޿�
//˽�пγ����÷����޸���Ϣ��...
//���ļ��ǵĲ������
//�ļ�Ϊ�յ�ʱ��������
#include<iostream>
#include<string>
#include<fstream>						//�ļ���������������
#include<iomanip>						//�������
using namespace std;
const char* filename="Student.txt";			//ѧ����Ϣ��¼���ļ�����
const char* filename_lesson="Lesson.txt";	//�����γ���Ϣ�ļ�¼����
const int MAX=10;							//���γ�����
struct Lesson_Node							//�γ̵Ľṹ������
{
	string L_name;							//�γ�����
	int grade;								//�γ̳ɼ�
};
class Lesson								//�γ�������
{
private:
	Lesson_Node lesson[MAX];				//�γ̾�����Ϣ�����10��
	int n;									//��ǰ�Ŀγ�����
	int Mount_s;							//�ɼ��ܺ�
	int Averg_s;							//ƽ���ɼ�
public:
	Lesson()								//�γ̳�ʼ������ȡ�ļ��й����γ̵���Ϣ����,���û���ļ��ͽ���һ���ļ�
	{
		ifstream ifs(filename_lesson);
		if(!ifs)
		{	
			string na[4]={"����","��ѧ","Ӣ��","����"};
			n=4;
			for(int i=0;i<n;++i)
			{
				lesson[i].L_name=na[i];
				lesson[i].grade=0;
			}
			SetA_M();
			Filein_PublicL();				//�����ʧ�ܣ���дһ���ļ�
		}
		else
		{
			ifs.close();
			Fileout_PbulicL();				//��ȡ�ɹ��Ͷ�ȡ��ǰ�ļ��еĿγ�����
			
		}
	}
	~Lesson()								//����
	{
		n=0;
		Mount_s=0;
		Averg_s=0;
	}
	Lesson(const Lesson&rhs)				//���ƹ��캯��
	{
		n=rhs.n;
		for(int i=0;i<n;i++)
		{
			lesson[i].L_name=rhs.lesson[i].L_name;
			lesson[i].grade=rhs.lesson[i].grade;
			SetA_M();
		}
	}
	Lesson& operator=(const Lesson&rhs)
	{
		n=rhs.n;
		for(int i=0;i<n;i++)
		{
			lesson[i].L_name=rhs.lesson[i].L_name;
			lesson[i].grade=rhs.lesson[i].grade;
			SetA_M();
		}
		return *this;
	}
	int ReturnMount_s()						//�����ܷ�
	{
		return Mount_s;
	}
	int ReturnAverg_s()						//����ƽ����
	{
		return Averg_s;
	}
	void Dislesson(int x=1)					//�����ǰ�Ŀγ̵���Ϣ
	{
		if(x==1)							//������Ҫ����û����������������Ĭ��������ļ��еĿγ���Ϣ���ڲ���x������1�������ǰ�ڴ����޸ĺ�Ŀγ̳���Ϣ
			Fileout_PbulicL();
		int i;
		for(i=0;i<n;i++)
		{
			cout<<i+1<<lesson[i].L_name<<"  ";
		}
		cout<<endl;
	}
	void Addlesson(int i=1)					//���ӿγ� ����1�ǹ����γ̵���� 2��˽�˿γ̵����
	{
		
		char t='1';
		string na;
		while(t=='1')
		{
			if(n==MAX)
			{
				cout<<"�Դﵽ�γ����ޣ��޷��������"<<endl;
				return ;
			}
			cout<<"����Ҫ��ӵĿγ����ƣ�";
			cin>>na;
			lesson[n].L_name=na;
			if(i==1)
			lesson[n].grade=0;
			else
			{
				cout<<"����ɼ�";
				cin>>na;
				lesson[n].grade=atoi(na.c_str());
			}
			n++;							//�γ�������1
			
			cout<<"�Ƿ������ӿγ̣���1.���� 0.���ˣ�";
			cin>>t;
		}
		if(i==1)
		Filein_PublicL();//���޸ĺ�Ŀγ���Ϣд���ļ�
	}	
	void Dellesson(int i=1)					//ɾ���γ�
	{
		int x;string tmp;char t='1';
		while(t=='1')
		{
			cout<<"������Ҫɾ���Ŀγ̱��";
			cin>>tmp;x=atoi(tmp.c_str());
			if(x>0&&x<=n)
			{
				for(;x<n;x++)
				{
					lesson[x-1].L_name=lesson[x].L_name;
					lesson[x-1].grade=lesson[x].grade;
				}
				n--;
				if(i==1)
				Dislesson(0);				//��ʾ��ǰ�ڴ��еĿγ���Ϣ������һֱѭ��ɾ��Ҫһֱ��ȡд���ļ�������һ���Խ��޸ĺõĿγ�д���ļ�
			}
			else
			{
				cout<<"�������~~~�����Ѿ������ڿγ���Ϣ��"<<endl;
			}
			cout<<"�Ƿ����ɾ���γ���Ϣ��1.�ǵģ�0.���ˣ� ";
			cin>>t;
		}
		if(i==1)
		Filein_PublicL();					//д���ļ�
	}
	void SetA_M()							//����ƽ���ֺ��ܷ�
	{
		Mount_s=0;
		for(int i=0;i<n;i++)
		{
			Mount_s=Mount_s+lesson[i].grade;
		}
		Averg_s=Mount_s/n;
	}
	/*******************************************     ����ѡ�޿γ�����     *********************************************/
	void SetPersonLesson()
	{
		string tmp;
		char x='0';
		int i;
		Dislesson(2);  cout<<endl;                             //�����ǰѧ����Ϣ�еĿγ���Ϣ
		cout<<"a.���ӿγ� b.ɾ���γ�";
		cin>>x;
		switch (x)
		{
		case 'a':Addlesson(2);break;							//���ӵ��˿γ�
		case 'b':Dellesson(2);break;							//ɾ�����˿γ�
		default:
			i=x-'0';
			if(i>0&&i<=n)
			{
				cout<<"������"<<lesson[i-1].L_name<<"�ĳɼ���";
				cin>>tmp;
				lesson[i-1].grade=atoi(tmp.c_str());//�ɼ����ַ�ת����
				
			}
			break;
		}SetA_M();
	}
	/*******************************************     �����γ����ò���     **********************************************/
	
	void Filein_PublicL()				//���ļ������빫���γ̵�����
	{
		ofstream ofs(filename_lesson);
		if(!ofs)
		{
			cout<<"�ļ���ʧ��"<<endl;
			exit(0);
		}
		ofs<<n<<'\t';
		for(int i=0;i<n;i++)
		{
			ofs<<lesson[i].L_name<<'\t';
		}
		ofs.close();

	}
	void Fileout_PbulicL()				//���ļ��ж�ȡ�����γ�������Ϣ�������γ�
	{
		int i=0;
		ifstream ifs(filename_lesson);
		if(!ifs)
		{
			cout<<"�ļ���ʧ��"<<endl;
			exit(0);
		}
		ifs>>n>>ws;
		while(i<n&&!ifs.eof())			//�ж��Ƿ��ȡ���ļ�ĩβ��
		{
			ifs>>lesson[i].L_name>>ws;
			i++;
		}
		ifs.close();
	}
	void SetPbulicLesson()				//���õ�ǰ�Ĺ����γ̵���Ϣ
	{
		cout<<"��ǰ�����γ���Ϣ��"<<endl;//��ʾ��ǰ�Ŀγ���Ϣ��������
		Dislesson();
		cout<<"1.��ӿγ�  2.ɾ���γ�  0.���� ";
		string tmp;char t;
		cin>>t;
		switch(t)
		{
		case '1':
			Addlesson();
			break;
		case '2':
			Dellesson();
			break;
		case '0':break;
		}
	}
	friend istream& operator>>(istream& is,Lesson &rhs)//����ɼ�
	{
		string tmp;
		for(int i=0;i<rhs.n;i++)
		{
			cout<<"������"<<rhs.lesson[i].L_name<<"�ĳɼ���";
			is>>tmp;
			rhs.lesson[i].grade=atoi(tmp.c_str());//�ɼ����ַ�ת����
		}
		return is;
	}
	friend ostream& operator<<(ostream& os,Lesson &rhs)//����ɼ�
	{
		for(int i=0;i<rhs.n;i++)
		{
			cout<<"|"<<rhs.lesson[i].L_name<<"|\t   "<<rhs.lesson[i].grade<<"\t";
		}
		cout<<endl;
		return os;
	}
	friend class student_Node;
	friend class student_List;
};
/*****************************************************************************************************************************/
Lesson L;//***********************************************************************************�����γ̱���
class student_Node		//ѧ������Ϣ�࣬�洢ѧ������Ϣ�����޸���Ϣ
{
private:
	string Name;		//����
	long Number;		//ѧ��
	string Sex;			//�Ա�
	string Academy;		//ѧԺ
	string Class;		//�༶
	Lesson Less;        //�γ�
	student_Node *next;
public:
	student_Node(string na="��",long num=0,string sex="��",string aca="��",string cla="��")		//�Գɼ����������Գ�Ա�����г�ʼ��??��Ҫ�Ż�?
		:Less(L)
	{
		SetName(na);
		SetNumber(num);
		SetSex(sex);
		SetAcademy(aca);
		SetClass(cla);
		next=NULL;
	}
	~student_Node()					//����
	{
		Name="";Number=0;Sex="";Academy="";Class="";next=NULL;
	}
	student_Node& operator =(const student_Node&rhs)
	{
		Name=rhs.Name;
		Number=rhs.Number;
		Sex=rhs.Sex;
		Academy=rhs.Academy;
		Class=rhs.Class;
		Less=rhs.Less;//�����ֵ��ÿγ���ĸ�ֵ����
		return *this;
	}
	void SetName(string name)		//��������
	{
		Name=name;
	}
	void SetNumber(long num )		//����ѧ��
	{
		Number=num;
	}
	void SetSex(string sex)			//�����Ա�
	{
		Sex=sex;
	}
	void SetAcademy(string acad)	//����ѧԺ
	{
		Academy=acad;
	}
	void SetClass(string cla )		//���ð༶
	{
		Class=cla;
	}
	void SetLesson()				//���˿γ�����
	{
		Less.SetPersonLesson();
	}
	friend istream& operator>>(istream&is,student_Node &rhs)//��������
	{
		string tmp;
		long num;
		cout<<"������������";		//�������֣�����ʱ�����У�Ȼ��ͨ�����ú������úó�Ա�е����֣�����Ķ���ͬ
		is>>tmp;
		rhs.SetName(tmp);
		cout<<"������ѧ�ţ�";
		is>>tmp;
		num=atol(tmp.c_str());		//�ַ���ת��Ϊ�����Σ�����������ַ�ʱ����ֵ�bug��
		rhs.SetNumber(num);
		cout<<"�������Ա�";
		is>>tmp;
		rhs.SetSex(tmp);
		cout<<"������ѧԺ��";
		is>>tmp;
		rhs.SetAcademy(tmp);
		cout<<"������༶��";
		is>>tmp;
		rhs.SetClass(tmp);
		is>>rhs.Less;				//����γ�
		return is;
	}
	friend ostream& operator<<(ostream&os,student_Node &rhs)//�������
	{
		cout<<left<<setw(8)<<rhs.Name<<left<<setw(15)<<rhs.Number<<left<<setw(8)<<rhs.Sex<<left<<setw(10)<<rhs.Academy<<left<<setw(10)<<rhs.Class<<left<<setw(8)<<rhs.Less.ReturnMount_s()<<left<<setw(8)<<rhs.Less.ReturnAverg_s()<<endl;

		cout<<rhs.Less<<endl;		//����γ�
		return os;
	}
	friend class  student_List;		//��Ԫ������
};
/*******************************************************************************************************************/
class student_List					//ѧ������Ϣ�����࣬��Ҫ��������Ĳ������������
{
private:
	student_Node *head;
public:
	student_List()					//ѧ������ĳ�ʼ��������ͷ���,�����ļ��ж�ȡ��Ϣ��������
	{
		head=new student_Node;
		head->next=NULL;
		ifstream ifs(filename);
		if(!ifs)					//����ļ�������
		{
			Filewrite();			//�����ļ�
		}
	}
	~student_List()
	{
		student_Node *p=head->next,*q;
		while(p!=NULL)
		{
			q=p;
			p=p->next;
			delete q;
		}
		delete head;
	}
	void Fileread()					//��ȡ�ļ��е���Ϣ��������
	{
		ifstream ifs(filename);
		if(!ifs)
		{
			cout<<"�ļ���ʧ��"<<endl;
			exit(0);
		}
		student_Node *q=head;
		while(ifs.peek()!=EOF)		//�ж��Ƿ��ȡ���ļ�ĩβ�� �������peek������������ifs.eof()�Ƿ�ֹ�ļ�Ϊ��ʱ������ѭ��
		{
			student_Node *p=new student_Node;
			ifs>>p->Name
				>>ws
				>>p->Number
				>>ws
				>>p->Sex
				>>ws
				>>p->Academy
				>>ws
				>>p->Class
				>>ws;
			ifs>>p->Less.n>>ws;
			for(int i=0;i<p->Less.n;i++)
				ifs>>p->Less.lesson[i].L_name>>ws>>p->Less.lesson[i].grade>>ws;
			p->Less.SetA_M();
			q->next=p;
			p->next=NULL;
			q=p;
		}
	}
	void Filewrite()				//ͨ���ļ��Ķ�д�������е�����д���ļ���
	{
		student_Node *p=head->next;
		ofstream ofs(filename);
		if(!ofs)
		{
			cout<<"�ļ���ʧ��"<<endl;
			exit(0);
		}
		while(p!=NULL)
		{
			ofs<<p->Name<<'\t'
				<<p->Number<<'\t'<<p->Sex<<'\t'<<p->Academy<<'\t'<<p->Class
				<<endl;
			ofs<<p->Less.n;
			for(int i=0;i<p->Less.n;i++)
				ofs<<'\t'<<p->Less.lesson[i].L_name<<'\t'<<p->Less.lesson[i].grade;
			ofs<<endl;
				p=p->next;
		}
		ofs.close();
	}
	/**********************************     ��������    ***********************************/
	void Putin(int n=1)			//����,�����ĺ������������ǲ���1�����뻹�ò��뺯��....Ĭ�������뺯��
	{
		char x='0';
		int i=1;				//����
		int num_0,num_1;//����λ��
		student_Node *q;
		if(n==1)				//���ǲ���������������Ҫ�ģ����������������Ҫ
		{
			cout<<"�Ƿ����ԭ������ 0.�ǵ� 1.������ӽ�ȥ 3.���� ";
			cin>>x;
			if(x=='1')//��ӽ�ȥ
			{
				Fileread();				//��ȡ�ļ��γ�����
				Putin(0);				//�����ĸı�,���ǲ��뺯���ĵ���
				return ;
			}
		}
		if(x=='0')
		{
			while(x=='0')
			{
				cout<<i++<<endl;
				student_Node *p=new student_Node;
				cin>>*p;
				if(n!=3)//�ڵ�Ĳ巨
				{
					p->next=head->next;
					head->next=p;
				}
				else//�ڵ������λ�ò���
				{
					Display(2);
					cout<<"----------------------------------------------------------------"<<endl;
					cout<<"��ѡ�����λ�ã�";
					cin>>x;
					num_0=x-'0';
					q=head;
					num_1=0;//Ѱ��λ��
					while (q->next!=NULL)
					{
						num_1++;
						if(num_0==num_1)
							break;
						q=q->next;
					}
					p->next=q->next;
					q->next=p;
					Display(2);
				}
				cout<<"������Ҫ����ô����0.�� 1.���ǣ� ";
				cin>>x;
				cout<<"----------------------------------------------------------------"<<endl;
			}
			Filewrite();
		}
	}
	void Display(int x=1)				//��ʾ���cout<<left<<setw(40)<<"�������"<<left<<setw(35)<<"�������"<<endl;
	{
		if(x==1)
			Fileread();
		cout<<left<<setw(5)<<"����š�"<<left<<setw(8)<<" ��������"<<left<<setw(15)<<" ��ѧ�š�"<<left<<setw(8)<<"���Ա�"<<left<<setw(10)<<"��ѧԺ��"<<left<<setw(10)<<"���༶��"<<left<<setw(8)<<"|�ܷ�|"<<left<<setw(8)<<"|ƽ����|"<<endl<<endl;
		student_Node *p=head->next;
		int i=1;
		while(p!=NULL)
		{
			cout<<left<<setw(3)<<" "<<left<<setw(3)<<i++<<"    "<<*p;
			p=p->next;
		}
		cin.get();
		cin.get();
	}
	void Insert()				//����(���)
	{
		Fileread();				//��ȡ�ļ��γ�����
		Putin(3);				//�����ĸı�,���ǲ��뺯���ĵ���

	}
	void Delete()				//ɾ��
	{
		Find(2);
		Filewrite();		//д���ļ�
	}
	void Find(int i=1)			//����
	{
		Fileread();//��ȡ�ļ��γ�����
		char x='0';
		while(x=='0')
		{
			cout<<"ѡ����ҷ�ʽ��1.����  2.ѧ��  3.ѧԺ   0.����";
			cin>>x;
			switch(x)
			{
			case '1':
				Find_01name(i);
				break;
			case '2':
				Find_02number(i);
				break;
			case '3':
				Find_03academy(i);
				break;
			case '0':return;
			default:
				cout<<"ѡ����󣡣���";
			}
			cout<<"�Ƿ�������� 0.���� 1.����  ";
			cin>>x;
		}
	}
	void Find_01name(int x=1)	//�������� ���� 1.���� 2.ɾ�� 3.�޸�
	{
		int i=0;
		string na;
		char x_0='1';
		student_Node *p=head->next,*q=head;
		cout<<"������Ҫ���ҵ�������";
		cin>>na;
		cout<<left<<setw(5)<<"����š�"<<left<<setw(8)<<" ��������"<<left<<setw(15)<<" ��ѧ�š�"<<left<<setw(8)<<"���Ա�"<<left<<setw(10)<<"��ѧԺ��"<<left<<setw(10)<<"���༶��"<<left<<setw(8)<<"|�ܷ�|"<<left<<setw(8)<<"|ƽ����|"<<endl<<endl;
		while(p!=NULL)
		{
			if(p->Name==na)
			{
				cout<<left<<setw(3)<<" "<<left<<setw(3)<<i++<<"    "<<*p;
				if(x==2)//ɾ������
				{
					cout<<"�Ƿ�ɾ���������� 0.�� 1.��";
					cin>>x_0;
					if(x_0=='0')
					{
						q->next=p->next;
						delete p;
						p=q;
					}
				}
				if(x==3)//�޸�����
				{
					cout<<"�Ƿ��޸��������� 0.�� 1.��";
					cin>>x_0;
					if(x_0=='0')
					{
						Modify_small(p);
					}
				}
			}
			
			q=p;
			p=p->next;
		}cout<<"-------------------------------------------------------"<<endl;
		if(i==0)
			cout<<"���������ô��û����Ҫ������"<<endl;
	}
	void Find_02number(int x=1)//ѧ�Ų���
	{
		int i=0;
		long num;
		string tmp;
		char x_0='1';
		student_Node *p=head->next,*q=head;
		cout<<"������Ҫ���ҵ�ѧ�ţ�";
		cin>>tmp;
		num=atol(tmp.c_str());
		cout<<left<<setw(5)<<"����š�"<<left<<setw(8)<<" ��������"<<left<<setw(15)<<" ��ѧ�š�"<<left<<setw(8)<<"���Ա�"<<left<<setw(10)<<"��ѧԺ��"<<left<<setw(10)<<"���༶��"<<left<<setw(8)<<"|�ܷ�|"<<left<<setw(8)<<"|ƽ����|"<<endl<<endl;
		while(p!=NULL)
		{
			if(p->Number==num)
			{
				cout<<left<<setw(3)<<" "<<left<<setw(3)<<i++<<"    "<<*p;
				if(x==2)//ɾ������
				{
					cout<<"�Ƿ�ɾ���������� 0.�� 1.��";
					cin>>x_0;
					if(x_0=='0')
					{
						q->next=p->next;
						delete p;
						p=q;
					}
				}
				if(x==3)//�޸�����
				{
					cout<<"�Ƿ��޸��������� 0.�� 1.��";
					cin>>x_0;
					if(x_0=='0')
					{
						Modify_small(p);
					}
				}
			}
			q=p;
			p=p->next;
		}
		cout<<"-------------------------------------------------------"<<endl;
		if(i==0)
			cout<<"���������ô��û����Ҫ������"<<endl;
	}
	void Find_03academy(int x=1)//ѧԺ����
	{
		int i=0;
		string tmp;
		char x_0='1';
		student_Node *p=head->next,*q=head;
		cout<<"������Ҫ���ҵ�ѧԺ��";
		cin>>tmp;
		cout<<left<<setw(5)<<"����š�"<<left<<setw(8)<<" ��������"<<left<<setw(15)<<" ��ѧ�š�"<<left<<setw(8)<<"���Ա�"<<left<<setw(10)<<"��ѧԺ��"<<left<<setw(10)<<"���༶��"<<left<<setw(8)<<"|�ܷ�|"<<left<<setw(8)<<"|ƽ����|"<<endl<<endl;
		while(p!=NULL)
		{
			if(p->Academy==tmp)
			{
				cout<<left<<setw(3)<<" "<<left<<setw(3)<<++i<<"    "<<*p;
				if(x==2)
				{
					cout<<"�Ƿ�ɾ���������� 0.�� 1.��";
					cin>>x_0;
					if(x_0=='0')
					{
						q->next=p->next;
						delete p;
						p=q;
					}
				}
				if(x==3)//�޸�����
				{
					cout<<"�Ƿ��޸��������� 0.�� 1.��";
					cin>>x_0;
					if(x_0=='0')
					{
						Modify_small(p);
					}
				}
			}
			q=p;
			p=p->next;
		}
		cout<<"-------------------------------------------------------"<<endl;
		if(i==0)
			cout<<"���������ô��û����Ҫ������"<<endl;
	}
	void Modify()		//�޸�             ���������һЩ�����������۶�
	{
		Find(3);
		Filewrite();		//д���ļ�
	}
	void Modify_small(student_Node *p)
	{
		char a='0';
		string tmp;
		long num;
		while(a=='0')
		{
			cout<<"-------------------------------------------------------"<<endl;
			cout<<"��ѡ���޸�ѡ��   1.���� 2.ѧ�� 3.�Ա� 4.ѧԺ 5.�༶ 6.�ɼ�";
            cin>>a;
			cout<<"-------------------------------------------------------"<<endl;
			switch(a)
			{
			case '1':
				cout<<"�������֣�";
				cin>>tmp;
				p->SetName(tmp);
				break;
			case '2':
				cout<<"����ѧ�ţ�";
				cin>>tmp;
				num=atol(tmp.c_str());
				p->SetNumber(num);
				break;
			case '3':
				cout<<"�����Ա�";
				cin>>tmp;
				p->SetSex(tmp);
				break;
			case '4':
				cout<<"����ѧԺ��";
				cin>>tmp;
				p->SetAcademy(tmp);
				break;
			case '5':
				cout<<"������༶��";
				cin>>tmp;
				p->SetClass(tmp);
				break;
			case '6':
				p->SetLesson();//�޸Ŀγ�
				break;
			default:
				cout<<"��ɰ�Ŷ�����������~"<<endl;
			}
			cout<<*p;
			cout<<"-------------------------------------------------------"<<endl;//�����Ӿ�Ч��
			cout<<"�Ƿ�����޸�����ѡ�� 0.���� 1.����";
			cin>>a;
		}
	}
	void Sort()			//����
	{
		Fileread();	
		char t='0';
		while (t=='0')
		{
			cout<<"------------------------------------------------------------"<<endl;
			cout<<"1.ѧ�� 2.���Ƴɼ� 3.�ܳɼ� 0.����";
			cin>>t;
			switch (t)
			{
			case '1':
				Sort_small(1);break;//ѧ������
			case '2':
				Sort_small(2);break;//���Ƴɼ�����
			case '3':
				Sort_small(3);break;//�ܳɼ�����
			default:
				Filewrite();//
				return ;
			}
			Display(0);
			cout<<"�Ƿ�������� 0.���� 1.����,��������";
			cin>>t;
		}
		Filewrite();		//д���ļ�
	}
	void Sort_small(int i=1)//��������֧�����ݲ����Ĳ�ͬ���в�ͬѡ�������1.Ĭ��ѧ�� 2.���Ƴɼ� 3.�ܳɼ�  
	{
		char t;int x;
		if(i==2)//���Ƴɼ�����ʱ���
		{
			L.Dislesson();//��ʾ�����γ�
			cin>>t;
			x=t-'0';//�γ̵��±�
			if(x>L.n||x<0)
			{
				cout<<"ѡ�����"<<endl;
				return ;
			}
		}
		cout<<"1.���� 2.�ݼ�";
		student_Node *p1,*p2;
		student_Node tmp;
		int flag=1;
		cin>>t;
			while(1)//ð������
			{
				flag=1;
				p1=head->next;p2=p1->next;
				while(p2!=NULL)
				{
					switch (t)
					{
					case '1':
						if(i==3)//�ܷ�����
							if(p1->Less.Mount_s>p2->Less.Mount_s)
							{
								tmp=*p1;
								*p1=*p2;
								*p2=tmp;
								flag=0;
							}
						if(i==2)//�ɼ�����
							if(p1->Less.lesson[x-1].grade>p2->Less.lesson[x-1].grade)
							{
								tmp=*p1;
								*p1=*p2;
								*p2=tmp;
								flag=0;
							}
						if(i==1)//ѧ������
							if(p1->Number>p2->Number)
							{
								tmp=*p1;
								*p1=*p2;
								*p2=tmp;
								flag=0;
							};break;
					case '2':
						if(i==3)//�ܷ�����
							if(p1->Less.Mount_s<p2->Less.Mount_s)
							{
								tmp=*p1;
								*p1=*p2;
								*p2=tmp;
								flag=0;
							}
						if(i==2)//�ɼ�����
							if(p1->Less.lesson[x-1].grade<p2->Less.lesson[x-1].grade)
							{
								tmp=*p1;
								*p1=*p2;
								*p2=tmp;
								flag=0;
							}
						if(i==1)//ѧ������
							if(p1->Number<p2->Number)
							{
								tmp=*p1;
								*p1=*p2;
								*p2=tmp;
								flag=0;
							};break;
					default:
						break;
					}
					
					p1=p1->next;
					p2=p2->next;
				}
				if(flag==1)
					break;
			}
	}
	void Cal()			//�������ѧ���ܳɼ���ƽ���ɼ�   ��Ҫǿ���书��
	{
		Fileread();	
		cout<<"-------------------------------------------------------------------"<<endl;
		cout<<left<<setw(10)<<"��Ŀ"<<left<<setw(10)<<"�ܷ�"<<left<<setw(10)<<"ƽ����"<<left<<setw(10)<<"ͨ����"<<endl;//�����ո�
		for(int i=0;i<L.n;i++)
			Cal_small(L.lesson[i].L_name);
		cin.get();cin.get();
	}
	void Cal_small(string na)
	{
		student_Node *p=head->next;
		int num_1=0,num_n=0,num_p=0;
		while(p!=NULL)
		{
			for(int i=0;i<p->Less.n;++i)
			{
				if(p->Less.lesson[i].L_name==na)
				{
					num_n++;//������
					num_1=num_1+p->Less.lesson[i].grade;
					if(p->Less.lesson[i].grade>=60)
						num_p++;//ͨ������
					break;
				}
			}
			p=p->next;
		}
		cout<<left<<setw(10)<<na<<left<<setw(10)<<num_1<<left<<setw(10)<<num_1/num_n<<left<<setw(3)<<(float)num_p/(float)num_n*100<<"%"<<endl;
	}
	float Grade_fail(string name ,int grade)		//����ɼ����ȫУ�İٷֱ�
	{
		int num_1=0,num_2=0;
		float num;
		student_Node *p=head->next;
		while (p!=NULL)
		{
			for(int i=0;i<p->Less.n;i++)
			{
				if(name==p->Less.lesson[i].L_name)//����ѡ���ſε���
				{
					num_1++;
					if(p->Less.lesson[i].grade<=grade)
						num_2++;//����������������
					break;
				}
			}
			p=p->next;
		}
		num=(float)num_2/(float)num_1*100;//����ת��
		return num;
	}
	void student_pass(string na ,string num )		//ѧ����½���
	{
		Fileread();
		student_Node *p=head->next;
		while(p!=NULL)
		{
			if(p->Name==na&&p->Number==atol(num.c_str()))
				break;
			p=p->next;
		}
		if(p==NULL)
		{
			cout<<"û�����ѧ������������";
			cin.get();cin.get();
			return ;
		}
		int i=0;
		system("cls");
		cout<<endl<<endl<<"����"<<p->Name<<",�ҵı����"<<p->Number<<",�Ա�"<<p->Sex<<",������"<<p->Academy<<p->Class<<"��,��ع�����~"<<endl<<endl;
		cout<<left<<setw(15)<<"ѧ��"<<" �ɼ�"<<endl;
		cout<<"-------------------------------------------------------------------------"<<endl;
		for(i=0;i<p->Less.n;i++)
		{
			cout<<left<<setw(15)<<p->Less.lesson[i].L_name<<" "<<p->Less.lesson[i].grade<<"          �Ҵ����ȫУ"<<Grade_fail(p->Less.lesson[i].L_name,p->Less.lesson[i].grade)<<"%����"<<endl;
			cout<<"-------------------------------------------------------------------------"<<endl;
		}
		cin.get();cin.get();
	}
};
const string Pass_word="123456";//��ʦ��½����
void Meue_studentpass()//ѧ����½
{
	student_List B;
	string na ,num;
	cout<<"\n\n                           ������ѧ�ţ�";
	cin>>num;
	cout<<"                           ���������֣�";
	cin>>na;
	B.student_pass(na,num);
}
void Meue()				//���˵�����
{
	while(1)
	{
	system("cls");
	cout<<"\n\n\n\n\n";
	cout<<"             ���ﵱ�Һ����粻һ�� �Ǿ����Ҳ�һ���ɡ��� "<<endl;
	cout<<"                    �x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x"<<endl;
	cout<<"                    ��                            ��"<<endl;
	cout<<"                    ��        1.����              ��"<<endl;
	cout<<"                    ��        2.���              ��"<<endl;
	cout<<"                    ��        3.�����γ�����      ��"<<endl;
	cout<<"                    ��        4.���              ��"<<endl;//��ɿ��������λ�õ�
	cout<<"                    ��        5.����              ��"<<endl;
	cout<<"                    ��        6.ɾ��              ��"<<endl;
	cout<<"                    ��        7.�޸�              ��"<<endl;
	cout<<"                    ��        8.����              ��"<<endl;
	cout<<"                    ��        9.����              ��"<<endl;
	cout<<"                    ��        0.�˳���½          ��"<<endl;
	cout<<"                    ��                            ��"<<endl;
	cout<<"                    ��������������������������������"<<endl;
	student_List A;//��������,��ʼ��
	char t;
	cin>>t;
	system("cls");
	switch (t)
	{
	case '1':
		A.Putin();
		break;
	case '2':
		A.Display();
		break;
	case '3':
		L.SetPbulicLesson();
		break;
	case '4':
		A.Insert();
		break;
	case '5':
		A.Find();
		break;
	case '6':
		A.Delete();
		break;
	case '7':
		A.Modify();
		break;
	case '8':
		A.Sort();
		break;
	case '9':
		A.Cal();break;
	case '0':return ;
	default:
		break;
	}
	}
}
void Welcome()			//��ʼ�ĵ�½����
{
	system("cls");

	cout<<"\n\n\n\n\n\n";
	cout<<"                            ��ѧ���ɼ�����ϵͳ��"<<endl;
	cout<<"                                              @by__��ΰ"<<endl;
	cout<<"                           �~�~�~�~�~�~�~�~�~�~�~"<<endl;
	cout<<"                           ��                  ��"<<endl;
	cout<<"                           ��    1.��ʦ��¼    ��"<<endl;
	cout<<"                           ��    2.ѧ����¼    ��"<<endl;
	cout<<"                           ��    0.��   ��     ��"<<endl;
	cout<<"                           ��                  ��"<<endl;
	cout<<"                           �~�~�~�~�~�~�~�~�~�~�~";
	char x;
	string tmp;
	cin>>x;
	switch(x)
	{
	case '0':exit(0);
	case '1':
		cout<<"\n\n                           ���������룺";
		cin>>tmp;
		if(tmp==Pass_word)					//�ж��Ƿ�ͨ������
			Meue();
		break;
	case '2':
		Meue_studentpass();
		break;
	}
	//_sleep(2*1000);//��ʱ����
}
int main()
{
	while(1)
	Welcome();
	return 0;
}