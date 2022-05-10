#include <iostream>
#include <string>
using namespace std;

#define CAD 3

class Data
{
    private:
        int dia;
        int mes;
        int ano;

    public:
        Data(int dia, int mes, int ano)
        {
            this->dia = dia;
            this->mes = mes;
            this->ano = ano;
        }

        Data()
        {
            this->dia = 1;
            this->mes = 1;
            this->ano = 1900;
        }

        void setDia(int dia)
        {
            this->dia = dia;
        }

        void setMes(int mes)
        {
            this->mes = mes;
        }

        void setAno(int ano)
        {
            this->ano = ano;
        }

        int getDia()
        {
            return this->dia;
        }

        int getMes()
        {
            return this->mes;
        }

        int getAno()
        {
            return this->ano;
        }

        string getData()
        {
            return to_string(this->dia) + "/" +
                to_string(this->mes) + "/" +
                to_string(this->ano);
        }

};

class Contato
{
    private:
        string email;
        string nome;
        string telefone;
        Data dtnasc;

    public:
        Contato(string email, string nome, string telefone, Data dtnasc)
        {
            this->email = email;
            this->nome = nome;
            this->telefone = telefone;
            this->dtnasc = dtnasc;
        }

        Contato()
        {
            this->email = "example@gmail.com";
            this->nome = "Example";
            this->telefone = "0000-0000";
            this->dtnasc = Data();
        }

        void setEmail(string email)
        {
            this->email = email;
        }

        void setNome(string nome)
        {
            this->nome = nome;
        }

        void setTelefone(string telefone)
        {
            this->telefone = telefone;
        }

        void setDtNasc(Data dtnasc)
        {
            this->dtnasc = dtnasc;
        }

        string getEmail()
        {
            return this->email;
        }

        string getNome()
        {
            return this->nome;
        }

        string getTelefone()
        {
            return this->telefone;
        }

        Data getDtNasc()
        {
            return this->dtnasc;
        }

        string getContato()
        {
            return "Email: " + this->email + "\n" +
                "Nome: " + this->nome + "\n" +
                "Telefone: " + this->telefone + "\n" +
                "Data de Nascimento: " + this->dtnasc.getData() + "\n" +
                "Idade: " + to_string(this->idade());
        }

        int idade()
        {
            int age = 2022 - this->dtnasc.getAno();
            return age;
        }
};


int main(int argc, char** argv)
{
    Contato *contato = new Contato[CAD]();
    string email, nome, telefone;
    int dia, mes, ano, contMaiores = 0, maisVelho;
	double mediaIdade = 0;
	
    for (int i = 0; i < CAD; i++)
    {
    	cout << "-------------------------------------------" << endl;
        cout << "Cadastro Contato " << i+1 << endl;
        cout << "Digite o email:" << endl;
        cin >> email;
        cout << "Digite o nome:" << endl;
        cin.ignore();
        getline(cin, nome);
        cout << "Digite o telefone:" << endl;
        cin >> telefone;
        cout << "Digite o dia do nascimento:" << endl;
        cin >> dia;
        cout << "Digite o mes do nascimento:" << endl;
        cin >> mes;
        cout << "Digite o ano do nascimento:" << endl;
        cin >> ano;

        Data *dtNasc = new Data(dia, mes, ano);
        contato[i].setEmail(email);
        contato[i].setNome(nome);
        contato[i].setTelefone(telefone);
        contato[i].setDtNasc(*dtNasc);
		mediaIdade += contato[i].idade();
		
        cout << "Cadastro finalizado" << endl;
        cout << "-------------------------------------------" << endl;
	}
    
    cout << "-------------------------------------------" << endl;
    mediaIdade /= CAD;
    cout << "Media de idade: " << mediaIdade << endl;
    cout << "-------------------------------------------" << endl;
    
    cout << "-------------------------------------------" << endl;
    cout << "Contatos com idade acima da media:" << endl;
    for (int i = 0; i < CAD; i++)
    {
    	if(contato[i].idade() > mediaIdade)
		{
			   cout << contato[i].getNome() << endl;	
		}
    }
    cout << "-------------------------------------------" << endl;
    
    cout << "-------------------------------------------" << endl;
    for (int i = 0; i < CAD; i++)
    {
    	if(contato[i].idade() >= 18)
		{
			   contMaiores++;	
		}
    }
    cout << "Quantidade de contatos maiores de idade: " << contMaiores << endl;
    cout << "-------------------------------------------" << endl;
    
    for(int i = 0; i < CAD; i++)
	{
		for(int j = 0; j < CAD; j++)
		{
			if(contato[i].idade() < contato[j].idade()){
				auto aux = contato[i];
				contato[i] = contato[j];
				contato[j] = aux;
			}
		}
	}    
	
	maisVelho =	contato[CAD-1].idade();
	
	cout << "-------------------------------------------" << endl;
	cout << "Contato(s) mais velho(s):" << endl;
	for(int i = 0; i < CAD; i++)
	{
		if(contato[i].idade() == maisVelho){
			cout << contato[i].getContato() << endl;
		}
	}
	cout << "-------------------------------------------" << endl;
	
    return 0;
}
