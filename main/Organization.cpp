/*
 *  Organization.h
 *
 *  Created on: 06-oct-2021
 *     Authors: Sunny Raj, M Somasekhar, Aryan Mukerji
 */

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

#include "main.h"
#include "Menu.h"
#include "Person.h"
#include "Transaction.h"
#include "Post.h"
#include "Block.h"

using namespace std;

Organization OrgList[N];
long OrgList_size = 0;

    void Organization::set_org_details(string org_name, string org_address, string org_phone_number)
    {
        this->org_name = org_name;
        this->org_address = org_address;
        this->org_phone_number = org_phone_number; 
    }
    
    void Organization::get_org_details()
    {
        cout << "\n\n ********** Organization Details ********** "
             << "\n\n Name : " << org_name
             << "\n Address : " << org_address
             << "\n Phone Number : " << org_phone_number;
    }
    
    void Organization::set_Org_ID()
    {
        this->Org_ID = OrgList_size + 1;
    }
	
    void Organization::set_Org_ID(long i)
	{
        Org_ID = i;
    }
    
    long Organization::get_Org_ID()
    {
        return Org_ID;
    }
    
    string Organization::get_org_name()
    {
        return org_name;
    }
    
    string Organization::get_org_address()
    {
        return org_address;
    }
    
    string Organization::get_org_phone_number()
    {
        return org_phone_number;
    }
    
    void Organization::set_registration_number(long registration_number)
    {
        this->registration_number = registration_number;
    }
    
    long Organization::get_registration_number()
    {
        return registration_number;
    }
	
// ------------------------------- To Make A Table -------------------------------
template<typename charT, typename traits = std::char_traits<charT> >

class center_helper 
{
    std::basic_string<charT, traits> str_;
    
    public:
    
    center_helper(std::basic_string<charT, traits> str) : str_(str) {}
    
    template<typename a, typename b>
    
    friend std::basic_ostream<a, b>& operator<<(std::basic_ostream<a, b>& s, const center_helper<a, b>& c);
};

template<typename charT, typename traits = std::char_traits<charT> >

center_helper<charT, traits> centered(std::basic_string<charT, traits> str) 
{
    return center_helper<charT, traits>(str);
}

// redeclare for std::string directly so we can support anything that implicitly converts to std::string
center_helper<std::string::value_type, std::string::traits_type> centered(const std::string& str) 
{
    return center_helper<std::string::value_type, std::string::traits_type>(str);
}

template<typename charT, typename traits>

std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits>& s, const center_helper<charT, traits>& c) 
{
    std::streamsize w = s.width();
    
    if (w > c.str_.length()) 
    {
        std::streamsize left = (w + c.str_.length()) / 2;
        s.width(left);
        s << c.str_;
        s.width(w - left);
        s << "";
    } 
    else 
    {
        s << c.str_;
    }
    
    return s;
}

void display_OrgList()
{
    if(OrgList_size == 0)
    {
        cout << "\n !!No Organization Found!! ";
        return ;
    }
	
	cout << "\n\n";
	cout << "+" << std::setw(40) << centered(" -------------------------------------- ")
		 << "+" << std::setw(40) << centered(" -------------------------------------- ")
		 << "+" << std::setw(80) << centered(" ------------------------------------------------------------------------------ ") 
		 << "+" << std::endl;
	
	cout << "|" << std::setw(40) << centered(" Organization ID ")
		 << "|" << std::setw(40) << centered(" Organization Name ")
         << "|" << std::setw(80) << centered(" Organization Address ") 
		 << "|" << std::endl;
							   
	cout << "+" << std::setw(40) << centered(" -------------------------------------- ")
		 << "+" << std::setw(40) << centered(" -------------------------------------- ")
		 << "+" << std::setw(80) << centered(" ------------------------------------------------------------------------------ ")
		 << "+" << std::endl;
    
    for(int i = 0; i < OrgList_size; i++)
    {
		cout << "|" << std::setw(40) << centered(to_string(OrgList[i].get_Org_ID()))
			 << "|" << std::setw(40) << centered(OrgList[i].get_org_name())
			 << "|" << std::setw(80) << centered(OrgList[i].get_org_address()) 
			 << "|" << std::endl;
		 
        // cout << "\n " << OrgList[i].get_Org_ID() << " : " << OrgList[i].get_org_name() << " | " << OrgList[i].get_org_address();
    }
	
	cout << "+" << std::setw(40) << centered(" -------------------------------------- ")
		 << "+" << std::setw(40) << centered(" -------------------------------------- ")
		 << "+" << std::setw(80) << centered(" ------------------------------------------------------------------------------ ")
		 << "+" << std::endl;
}

void add_org_to_list(Organization &o)
{
    OrgList[OrgList_size] = o;
    OrgList_size++;
    
    cout << "\n !!Organization Added successfully!! ";
}

bool verify_org(long Org_ID)
{
    bool found = true;
	
    ifstream OrgFile("org_id.txt");

    long a, decision = 0;
    
    while (OrgFile >> a)
    {
        if(a == Org_ID)
        {
            decision=1;
            break;
        }
    }

    if(decision == 1)
	{
        found = true;
	}

    else
	{
        found = false;
	}
	
    return found;
}

void create_org()
{
    ClearOS();
    
    long registration_number;
    
    cout << "\n\n Enter the Organization Registration Number : ";
    cin >> registration_number;
    //////////// !!! gives error if given character input !!!	
    
    if(verify_org(registration_number))
    {
        enter_org_details(registration_number);
    }
    else
    {
        cout << "\n !!Verification Failed, Organization not valid!! ";
    }
}

void intitialise_OrgList()
{
    Organization org1, org2, org3, org4;
    
    org1.set_Org_ID();
    org1.set_registration_number(1);
    org1.set_org_details("Nazareth Hospital", "Prayagraj, Uttar Pradesh", "7393254831");
    
    add_org_to_list(org1);
    
    org2.set_Org_ID();
    org2.set_registration_number(2);
    org2.set_org_details("Medanta Medicity", "Gurugram, Haryana", "8527690666");

    add_org_to_list(org2);
    
    org3.set_Org_ID();
    org3.set_registration_number(3);
    org3.set_org_details("Priti Hospital", "Prayagraj, Uttar Pradesh", "6393283820");
    
    add_org_to_list(org3);
    
    org4.set_Org_ID();
    org4.set_registration_number(4);
    org4.set_org_details("Lalitha Hospital", "New Delhi, Delhi", "9811898880");
    
    add_org_to_list(org4);

    post_init();
}
