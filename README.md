# GCC_VTABLE_FIX
# Virtual methods inheritance fix in the Arm GNU Toolchain arm-none-eabi 12.2 rel 1

Если с ОЗУ вдруг случилась беда, | 
В наследнике странность, проблема видна, | 
Виртуальных методов сбой происходит, | 
Таблица как будто вдруг путь свой теряет. | 

Не паникуй — решение есть, | 
Чтоб код заработал, и всё стало здесь: | 
Конструктор родной вызови ещё раз, | 
Тогда VMT восстановится в час. | 

# ЗДЕСЬ ИСПОЛЬЗУЕТСЯ ОПЕРАТОР «new» В ТАКОМ ФОРМАТЕ:
# void* operator new (size_t sz, void* p) { return p; }
(если он не определён, то его необходимо прописать именно так)
