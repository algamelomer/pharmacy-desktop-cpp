#pragma once

using namespace System;

public ref class User
{
public:
    int Id;
    String^ Username;
    String^ Password;
};

public ref class UserDBHelper
{
public:
    static bool ValidateUser(String^ username, String^ password);
};
