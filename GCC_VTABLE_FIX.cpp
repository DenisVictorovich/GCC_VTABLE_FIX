
/* GCC_VTABLE_FIX.cpp */

class BASE_class
{
    public:
        virtual void method() = 0;
} ;

class FIRST_class : public BASE_class
{
    public:
        void method() { /* НАШ ЗАВЕТНЫЙ МЕТОД ) */ }
} ;

FIRST_class FIRST_object;
const FIRST_class * array[] { &FIRST_object, &FIRST_object, &FIRST_object, nullptr } ;

class SECOND_class
{
    public:
        SECOND_class(BASE_class ** const array) : array(array) {}
        void method()
        {
            for ( int i = 0; array[i] != nullptr; i++ )
                /// РАНЬШЕ ЗДЕСЬ СИСТЕМА "ПАДАЛА" В ИСКЛЮЧЕНИЕ, ПЫТАЯСЬ ВЫЗВАТЬ НЕСУЩЕСТВУЮЩИЙ МЕТОД
                array[i] -> method();
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

