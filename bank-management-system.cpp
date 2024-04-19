#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;

void open_account()
{
  fstream fout;
  fout.open("bank.csv", ios::out | ios::app);

  string name, address, acc_type;
  int balance;
  cout << "Name : ";
  cin.ignore();
  cin >> name;
  cout << "Address : ";
  cin.ignore();
  cin >> address;
  cout << "Type of account saving (S) or currunt (C) : ";
  cin >> acc_type;
  cout << "Amount to deposite : ";
  cin >> balance;
  fout
      << name << ", "
      << address << ", "
      << acc_type << ", "
      << balance << "\n";
  cout << "Account is created \n";
}

void deposite_money()
{
  fstream fin, fout;
  fin.open("bank.csv", ios::in);
  fout.open("banknew.csv", ios::out);

  int balance, amount, count = 0, i;
  string name, acc_name, line, word;
  vector<string> row;

  cout << "Enter the name : ";
  cin >> name;
  cout << "Amount to deposite : ";
  cin >> amount;
  cout << "\n\n";

  while (!fin.eof())
  {
    row.clear();

    getline(fin, line);
    stringstream s(line);

    string del = ", ";
    int start, end = -1 * del.size();
    do
    {
      start = end + del.size();
      end = line.find(del, start);
      word = line.substr(start, end - start);
      row.push_back(word);
    } while (end != -1);

    acc_name = row[0];
    int row_size = row.size();

    if (name == acc_name)
    {
      count = 1;
      balance = stoi(row[3]) + amount;
      cout << "Total amount deposited : " << balance << "\n";
      stringstream convert;
      convert << balance;
      row[3] = convert.str();

      if (!fin.eof())
      {
        for (i = 0; i < row_size - 1; i++)
        {
          fout << row[i] << ", ";
        }

        fout << row[row_size - 1] << "\n";
      }
    }
    else
    {
      if (!fin.eof())
      {
        for (i = 0; i < row_size - 1; i++)
        {
          fout << row[i] << ", ";
        }
        fout << row[row_size - 1] << "\n";
      }
    }
    if (fin.eof())
      break;
  }
  if (count == 0)
    cout << "Account not found\n";

  fin.close();
  fout.close();
  remove("bank.csv");
  rename("banknew.csv", "bank.csv");
}

void withdraw_money()
{
  fstream fin, fout;
  fin.open("bank.csv", ios::in);
  fout.open("banknew.csv", ios::out);

  int balance, amount, count = 0, i;
  string name, acc_name, line, word;
  vector<string> row;

  cout << "Enter the name : ";
  cin >> name;
  cout << "Amount to withdraw : ";
  cin >> amount;
  cout << "\n\n";

  while (!fin.eof())
  {
    row.clear();

    getline(fin, line);
    stringstream s(line);

    string del = ", ";
    int start, end = -1 * del.size();
    do
    {
      start = end + del.size();
      end = line.find(del, start);
      word = line.substr(start, end - start);
      row.push_back(word);
    } while (end != -1);

    acc_name = row[0];
    int row_size = row.size();

    if (name == acc_name)
    {
      count = 1;
      balance = stoi(row[3]) - amount;
      cout << "Total amount deposited : " << balance << "\n";
      stringstream convert;
      convert << balance;
      row[3] = convert.str();

      if (!fin.eof())
      {
        for (i = 0; i < row_size - 1; i++)
        {
          fout << row[i] << ", ";
        }

        fout << row[row_size - 1] << "\n";
      }
    }
    else
    {
      if (!fin.eof())
      {
        for (i = 0; i < row_size - 1; i++)
        {
          fout << row[i] << ", ";
        }
        fout << row[row_size - 1] << "\n";
      }
    }
    if (fin.eof())
      break;
  }
  if (count == 0)
    cout << "Account not found\n";

  fin.close();
  fout.close();
  remove("bank.csv");
  rename("banknew.csv", "bank.csv");
}

void display_account()
{
  fstream fin;
  fin.open("bank.csv", ios::in);

  int count = 0;
  string name, acc_name;
  cout << "Enter the name : ";
  cin >> name;
  cout << "\n\n";

  vector<string> row;
  string line, word, temp;
  int balance;

  while (getline(fin, line))
  {

    row.clear();
    stringstream s(line);

    string del = ", ";
    int start, end = -1 * del.size();
    do
    {
      start = end + del.size();
      end = line.find(del, start);
      word = line.substr(start, end - start);
      row.push_back(word);
    } while (end != -1);
    acc_name = row[0];

    if (name == acc_name)
    {
      count = 1;
      cout << "Your full name : " << row[0] << "\n";
      cout << "Your address : " << row[1] << "\n";
      cout << "Type of account that you open : " << row[2] << "\n";
      cout << "Amount you deposite : " << row[3] << "\n";
      break;
    }
  }
  if (count == 0)
    cout << "Account not found\n";
}

void delete_account()
{
  fstream fin, fout;
  fin.open("bank.csv", ios::in);
  fout.open("banknew.csv", ios::out);

  int count = 0, i;
  string name, acc_name, line, word;
  vector<string> row;

  cout << "Enter the name : ";
  cin >> name;
  cout << "\n\n";

  while (!fin.eof())
  {

    row.clear();
    getline(fin, line);
    stringstream s(line);

    string del = ", ";
    int start, end = -1 * del.size();
    do
    {
      start = end + del.size();
      end = line.find(del, start);
      word = line.substr(start, end - start);
      row.push_back(word);
    } while (end != -1);

    acc_name = row[0];
    int row_size = row.size();

    if (name != acc_name)
    {
      if (!fin.eof())
      {
        for (i = 0; i < row_size - 1; i++)
        {
          fout << row[i] << ", ";
        }
        fout << row[row_size - 1] << "\n";
      }
    }
    else
    {
      count = 1;
    }
    if (fin.eof())
      break;
  }
  if (count == 1)
    cout << "Account deleted\n";
  else
    cout << "Account not found\n";

  fin.close();
  fout.close();
  remove("bank.csv");
  rename("banknew.csv", "bank.csv");
}

int main()
{
  int ch;
  while (true)
  {
    cout << "1) Open account \n";
    cout << "2) Deposite money \n";
    cout << "3) Withdraw money \n";
    cout << "4) Display account \n";
    cout << "5) Delete account \n";
    cout << "6) Exit \n";
    cout << "Select the option from above \n";
    cin >> ch;
    switch (ch)
    {
    case 1:
      cout << "1) Open account \n";
      open_account();
      cout << "\n\n";
      break;
    case 2:
      cout << "2) Deposite money \n";
      deposite_money();
      cout << "\n\n";
      break;
    case 3:
      cout << "3) Withdraw money \n";
      withdraw_money();
      cout << "\n\n";
      break;
    case 4:
      cout << "4) Display account \n";
      display_account();
      cout << "\n\n";
      break;
    case 5:
      cout << "5) Delete account \n";
      delete_account();
      cout << "\n\n";
      break;
    case 6:
      cout << "6) Exit \n";
      exit(1);
      break;
    default:
      cout << "This is not exist try again \n";
    }
  }
  return 0;
}