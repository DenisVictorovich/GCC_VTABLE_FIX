
/* GCC_VTABLE_FIX.cpp */

#pragma once

class BASE_class
{
    public:
        virtual void method() = 0;
} ;

class FIRST_class : public BASE_class
{
    public:
        void method() { debug_printf_NDV ( "ВЫЗОВ %s\r", __PRETTY_FUNCTION__ ) ; }
} ;

FIRST_class FIRST_object;
const FIRST_class * array[] { &FIRST_object, &FIRST_object, &FIRST_object, nullptr } ;

class SECOND_class
{
    public:
        SECOND_class(BASE_class ** const array) : array(array) {}
        void method()
        {
            for ( u8 i = 0; array[i] != nullptr; i++ )
                array[i] -> method() ;
        }
    private:
        BASE_class ** const array = nullptr;
} ;

SECOND_class SECOND_object(nullptr);

void test_routine()
{
    /// ЗДЕСЬ ИСПОЛЬЗУЕТСЯ ОПЕРАТОР «new» В ТАКОМ ФОРМАТЕ:
    /// void* operator new (size_t sz, void* p) { return p; }
    new (&FIRST_object) FIRST_class()/* ДОПОЛНИТЕЛЬНЫЙ ВЫЗОВ КОНСТРУКТОРА, ЧТОБЫ ВОССТАНОВИТЬ «object . Virtual_Method_Table» */;
    new (&SECOND_object) SECOND_class ( (BASE_class ** const)array ) ;
    SECOND_object.method();
}

