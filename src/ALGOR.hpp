/* ******************************   ALGOR.hpp   ******************************* *
 * ---------------------------------------------------------------------------- *
 *                                                                              *
 * Copyright © 2021-2022 Kalynovsky Valentin. All rights reserved.              *
 *                                                                              *
 * Licensed under the Apache License, Version 2.0 (the "License");              *
 * you may not use this file except in compliance with the License.             *
 * You may obtain a copy of the License at                                      *
 *                                                                              *
 *     http://www.apache.org/licenses/LICENSE-2.0                               *
 *                                                                              *
 * Unless required by applicable law or agreed to in writing, software          *
 * distributed under the License is distributed on an "AS IS" BASIS,            *
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.     *
 * See the License for the specific language governing permissions and          *
 * limitations under the License.                                               *
 *                                                                              *
 * ---------------------------------------------------------------------------- *
 * **************************************************************************** *
 * ---------------------------------------------------------------------------- *
 *                             Version: 1.0.0.0-dev                             *
 * ---------------------------------------------------------------------------- *
 * **************************************************************************** *
 * ---------------------------------------------------------------------------- *
 *                                                                              *
 *                              Project Structure:                              *
 * 1. ALGOR_CORE		-> basic structures and functions of the library        *
 * 2. ALGOR_EXCEPTION	-> class for working with exceptions                    *
 * 3. ALGOR_RANDOM		-> own random number generators                         *
 * 4. ALGOR_ARRAY		-> class for working with arrays                        *
 * 5. ALGOR_SORTING		-> sets of sorting methods                              *
 * 6. ALGOR_MATRIX		-> class for working with matrices                      *
 * 7. ALGOR_HEAP		-> class for working with trees                         *
 * 8. ALGOR_LIST		-> class for working with lists                         *
 *                                                                              *
 * ---------------------------------------------------------------------------- *
 * **************************************************************************** */

/*!
 * \file
 * \brief Бібліотека для обробки та сортування структур даних.
 * \author Калиновський Валентин
 * \version 1.0.0.0
 * \date 11.01.2022
 * \copyright Copyright © 2021-2022 Kalynovsky Valentin. All rights reserved.
   Licensed under the Apache License, Version 2.0 (the "License")
 */

// WARNING Дату написания документации указать тогда, когда будет написана документация

#ifndef ALGOR_HPP
#define ALGOR_HPP

/*!
  \namespace ALGOR
  \brief Глобальний простір імен усього проекту
  \details Призначений для зберігання усього реалізованого функціоналу проекту.
  Краще не використовувати разом з std, інакше можуть виникнути конфлікти.
  \since v0.1.2.0 commit 2fa93b
 */
namespace ALGOR
{
	/* ****+/^^^/+++++-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+++++/^^^/+**** *
	 * #*****+/^^^/+++++-/+/-+-+                         +-+-/+/-+++++/^^^/+*****# *
	 * #*-*%*-*+                                                         +*-*%*-*# *
	 * %%%%%                       $------------------$                      %%%%% *
	 * -->                              ALGOR_CORE                             <-- *
	 * %%%%%                       $------------------$                      %%%%% *
	 * #*-*%*-*+                                                         +*-*%*-*# *
	 * #*****+/^^^/+++++-/+/-+-+                         +-+-/+/-+++++/^^^/+*****# *
	 * ****+/^^^/+++++-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+++++/^^^/+**** */

	/*!
	  \brief Аліас для char <em>(1 байт)</em>.
	  \details Зазвичай використовується для задання типу строк. Може зберігати
	  число від <b>0</b> до <b>255</b>, або від <b>-128</b> до <b>+127</b>.
	  \since v0.1.3.0 commit b50b4a
	  \note Якщо цей тип дійсно використовується для строк, то не забувайте
	  вказувати "*" (вказівник) перед назвою імені строки, так як цей тип
	  не замінює повністю char на string. Це лише звичайний аліас.
	 */
	using byte1_t = char;
	/*!
	  \brief Аліас для short <em>(2 байти)</em>.
	  \details Зазвичай використовується при зберіганні коротких чисел
	  від <b>0</b> до <b>65'535</b>, або від <b>-32'768</b> до <b>+32'767</b>.
	  \since v0.1.3.0 commit b50b4a
	 */
	using byte2_t = short;
	/*!
	  \brief Аліас для long <em>(4 байти)</em>.
	  \details Зазвичай використовується при зберіганні чисел. Може
	  зберігати від <b>0</b> до <b>4'294'967'295</b>, або від <b>-2'147'483'648</b>
	  до <b>+2'147'483'647</b>.
	  \since v0.1.3.0 commit b50b4a
	  \note Також ним можна повноцінно замінити тип int, так як він теж
	  розрахований на 4 байти. Але якщо програму запустити на комп'ютері
	  з процесором intel i386 чи більш ранішим, то під int буде виділятися усього
	  2 байти і на тих процесорах int є аліасом для short. Через таке розпливчате
	  поняття типу int він ніде у бібліотеці не використовується, а використовуються
	  чіткі типи типу short чи long.
	 */
	using byte4_t = long;
	/*!
	  \brief Аліас для long long <em>(8 байтів)</em>.
	  \details Є розширенням типу long у два рази і розрахований під числа від <b>0</b>
	  до <b>18'446'744'073'709'551'615</b>, або від <b>-9'223'372'036'854'775'808</b>
	  до <b>+9'223'372'036'854'775'807</b>.
	  \since v0.1.3.0 commit b50b4a
	 */
	using byte8_t = long long;
	/*!
	  \brief Аліас для signed char <em>(1 байт)</em>.
	  \details Аналогічно звичайному char, але може приймати значення тільки
	  від <b>-128</b> до <b>+127</b>.
	  \since v0.1.0.0 commit 0d3195
	 */
	using sbit8_t = signed char;
	/*!
	  \brief Аліас для signed short <em>(2 байти)</em>.
	  \details Аналогічно звичайному short, але може приймати значення тільки
	  від <b>-32'768</b> до <b>+32'767</b>.
	  \since v0.1.0.0 commit 0d3195
	 */
	using sbit16_t = signed short;
	/*!
	  \brief Аліас для signed long <em>(4 байти)</em>.
	  \details Аналогічно звичайному long, але може приймати значення тільки
	  від <b>-2'147'483'648</b> до <b>+2'147'483'647</b>.
	  \since v0.1.0.0 commit 0d3195
	 */
	using sbit32_t = signed long;
	/*!
	  \brief Аліас для signed long long <em>(8 байтів)</em>.
	  \details Аналогічно звичайному long long, але може приймати значення тільки
	  від <b>-9'223'372'036'854'775'808</b> до <b>+9'223'372'036'854'775'807</b>.
	  \since v0.1.0.0 commit 0d3195
	 */
	using sbit64_t = signed long long;
	/*!
	  \brief Аліас для unsigned char <em>(1 байт)</em>.
	  \details Аналогічно звичайному char і на відміну від signed char може
	  приймати значення тільки від <b>0</b> до <b>255</b>.
	  \since v0.1.0.0 commit 0d3195
	 */
	using ubit8_t = unsigned char;
	/*!
	  \brief Аліас для unsigned short <em>(2 байти)</em>.
	  \details Аналогічно звичайному short і на відміну від signed short може
	  приймати значення тільки від <b>0</b> до <b>65'535</b>.
	  \since v0.1.0.0 commit 0d3195
	 */
	using ubit16_t = unsigned short;
	/*!
	  \brief Аліас для unsigned long <em>(4 байти)</em>.
	  \details Аналогічно звичайному long і на відміну від signed long може
	  приймати значення тільки від <b>0</b> до <b>4'294'967'295</b>.
	  \since v0.1.0.0 commit 0d3195
	 */
	using ubit32_t = unsigned long;
	/*!
	  \brief Аліас для unsigned long long <em>(8 байтів)</em>.
	  \details Аналогічно звичайному long long і на відміну від signed long long
	  може приймати значення тільки від <b>0</b> до <b>18'446'744'073'709'551'615</b>.
	  \since v0.1.0.0 commit 0d3195
	 */
	using ubit64_t = unsigned long long;
	/*!
	  \brief Аліас для float <em>(4 байти)</em>.
	  \details На відміну від всіх попередніх типів, що можуть зберігати тільки
	  цілі числа, тип \a float може зберігати числа з плаваючою комою. У
	  комірку можна записати як додатні, так і від'ємні числа. Можливий діапазон
	  зберігаємих чисел від <b>+/-3.4E-38</b> до <b>3.4E+38</b>.
	  \since v0.1.2.0 commit 1981d6
	 */
	using fbit32_t = float;
	/*!
	  \brief Аліас для double <em>(8 байтів)</em>.
	  \details Розширює тип \a float, збільшуючи точність та розмір у два рази.
	  Можливий діапазон зберігаємих чисел від <b>+/-1.7E-308</b> до <b>1.7E+308</b>.
	  \since v0.1.2.0 commit 1981d6
	 */
	using fbit64_t = double;
	/*!
	  \brief Аліас для long double <em>(16 байт)</em>.
	  \details Розширює тип \a double, збільшуючи точність та розмір іще у два
	  рази.
	  \since v0.1.3.0 commit b6349a
	 */
	using fbit128_t = long double;
	/*!
	  \brief Псевдонім для визначення типу <em>"розмір массиву"</em>.
	  \details Зазвичай цей тип використовується, коли треба вказати розмір масиву
	  чи позицію у масиві. Так як нумерація починається з 0 і не існує від'ємних
	  розмірів масивів чи номерів позицій, можна поточнити тип з <a>int</a> до
	  <a>unsigned int</a>. До того ж не завжди вистачає <b>65'535</b> комірок масиву.
	  Іноді потрібно більше, наприклад, мільйон чи мільярд. Більше мільярда нема
	  сенсу створювати структури даних тому ідеальним вибором серед <a>short</a>,
	  <a>long</a> та <a>long long</a> є <a>long</a>. Саме тому <a>asize_t</a> є
	  аліасом до <a>ubit32_t</a>.
	  \since v0.1.0.0 commit 89658e
	 */
	using asize_t = ubit32_t;
	/*!
	  \brief Псевдонім для обчислюваної <em>комірки пам'яті</em>.
	  \details використовується тільки у функції \a getMemoryCell(). Є службовим типом
	  і замість нього краще використовувати \a ubit64_t.
	  \since v0.1.1.3 commit b4cdc9
	 */
	using memcell_t = ubit64_t;

	/*!
	   \fn swap(type_value &firstNumber, type_value &secondNumber)
	   \brief Міняє місцями два елементи
	   \details Функція приймає два значення, які треба замінити місцями. Після
	   виконання функції перша комірка пам'яті буде зберігати друге значення, а
	   друга - перше. Для виконання алгоритму використовується додаткова
	   комірка пам'яті.
	   \tparam type_value Тип елементів, що міняються місцями
	   \param[in, out] firstNumber Перший елемент для заміни
	   \param[in, out] secondNumber Другий елемент для заміни
	   \since v0.0.0.1
	   \paragraph Приклад
	   \code{.cpp}
	   int value1 = 5, value2 = 10;
	   CORE::swap(value1, value2);
	   cout << value2 << "\n"; //print 5
	   \endcode
	   \paragraph Реалізація
	 */
	template <typename type_value>
	void swap(type_value &firstNumber, type_value &secondNumber) noexcept;
	/*!
	   \fn minimum(type_value firstNumber, type_value secondNumber)
	   \brief Повертає найменше значення з двух наданих
	   \details Функція приймає два значення і порівнює їх. Якщо перше
	   число виявится меншим за друге - функція повертає перше число, інакше -
	   друге.
	   \tparam type_value Тип елементів, з яких вибирається найменше значення
	   \param[in] firstNumber Перше значення на вибірку
	   \param[in] secondNumber Друге значення на вибірку
	   \since v0.1.1.4 commit 090b06
	   \return найменше значення з двух наданих
	   \paragraph Приклад
	   \code{.cpp}
	   int value1 = 5, value2 = 10;
	   cout << CORE::minimum(value1, value2) << "\n"; //print 5
	   \endcode
	   \paragraph Реалізація
	 */
	template <typename type_value>
	type_value minimum(type_value firstNumber, type_value secondNumber) noexcept;
	/*!
	   \fn maximum(type_value firstNumber, type_value secondNumber)
	   \brief Повертає найбільше значення з двух наданих
	   \details Функція приймає два значення і порівнює їх. Якщо перше
	   число виявится більшим за друге - функція повертає перше число, інакше -
	   друге.
	   \tparam type_value Тип елементів, з яких вибирається найбільше значення
	   \param[in] firstNumber Перше значення на вибірку
	   \param[in] secondNumber Друге значення на вибірку
	   \since v0.1.1.4 commit 090b06
	   \return найбільше значення з двух наданих
	   \paragraph Приклад
	   \code{.cpp}
	   int value1 = 5, value2 = 10;
	   cout << CORE::maximum(value1, value2) << "\n"; //print 10
	   \endcode
	   \paragraph Реалізація
	 */
	template <typename type_value>
	type_value maximum(type_value firstNumber, type_value secondNumber) noexcept;
	/*!
	   \fn getMemoryCell(memcell_t right_adjust = 0, memcell_t left_adjust = 0)
	   \brief Повертає випадкове число; аналог time(NULL)
	   \details Цей метод виділяє пам'ять під 10 комірок пам'яті. Куди саме система
	   виділить пам'ять передгадати неможливо, а також неможливо передгадати, яка
	   програма і які данні раніше сюди записувала, тому це самий реальний генератор
	   випадкович чисел. Поки генерація масивів не була доведена до ідеалу, але як
	   генераточ великого числа замість time(NULL) цілком реально використати. Із
	   десяти випадкових чисел функція розраховує число, яке треба повернути.
	   \param[in] right_adjust Правий здвиг
	   \param[in] left_adjust Лівий здвиг
	   \since v0.1.1.3 commit b4cdc9
	   \remark Функції можна задати бітовий здвиг. Якщо функція використовується
	   замість time(NULL), а результат передається у іншу функцію, що приймає тільки
	   чотири-байтове значення, можна задати правий здвиг на 32 біти (4 байти) і
	   тоді функція поверне 4 старших байти.
	   \retval cell - розраховане випадкове число
	   \paragraph Приклад
	   \code{.cpp}
	   cout << CORE::getMemoryCell() << "\n"; //print 185214324139604
	   \endcode
	   \paragraph Реалізація
	 */
	memcell_t getMemoryCell(memcell_t right_adjust = 0, memcell_t left_adjust = 0);

	/*!
	   \interface Printer
	   \brief Printer-інтерфейс, призначений для реалізації функціоналу виводу
	   інформації
	   \details Це є інтерфейс, що складається лише з одного віртуального методу, який
	   призначений для виводу інформації. Так як цей проект є унікальним у тому сенсі,
	   що не використовується жодна інша бібліотека (навіть стандартна) і автор
	   власноруч пише власну реалізацію алгоритмів - тому неможливо використати
	   клас iostream, через що неможлива реалізація принтеру. Автору потрібно буде з
	   початку написати власний клас вводу-виводу, а в умовах популярності графічних
	   інтерфейсів це не є оптимальним та актуальним. Краще програмісту самому дати
	   реалізувавти ввод-вивід. До того ж такий метод є універсальним: його можна
	   використовувати й у консольних програмах, й у графічних. Якби я намагався
	   власноруч написати реалізацію, вона була б спеціалізованою чи під консоль, чи
	   під графіку. Саме це мене підштовхнуло написати саме інтрерфейс, а не клас.
	   \since v0.1.2.0 commit 2fa93b
	   \remark
	   Раджу використовувати наступну реалізацію для консольної програми:
	   \code{.cpp}
	   template <typename type_array>
	   class printer : public CORE::Printer
	   {
	   public:
		   void setData(Array<type_array> **ARRAY)
		   {
			   Array = ARRAY;
		   }
		   void print() override
		   {
			   for (asize_t i = 0; i < (*Array)->array_size; i++)
			   {
				   cout << " " << (*Array)->array[i];
			   }
			   cout << "\n";
		   }
	   private:
		   Array<type_array> **Array;
	   };
	   \endcode
	   Цей клас зберігає не матрицю, а вказівник на вказівник на структуру масиву.
	   Тому достатньо один раз передати у клас вказівник на структуру і все. Далі
	   можна просто міняти вказівники на інші структури з іншими масивами і не
	   треба їх заново передавати у цей клас. Він сам буде відстежувати, який
	   вказівник зберігається у вказівнику на структуру.
	 */
	class Printer
	{
	public:
		/*!
		   \brief Метод для виводу інформації
		   \since v0.1.2.0 commit 2fa93b
		   \paragraph Приклад
		   \code{.cpp}
		   //Створюю вказівник на структуру
		   Array<byte8_t> *D;

		   //Створюю об'єкт принтера і передаю йому посилання на структуру
		   printer<byte8_t> *pr = new printer<byte8_t>;
		   pr->setData(&D);

		   //Створюю об'єкт класу масиву та генерую данні
		   ARRAYDATA<byte8_t> *A = new ARRAYDATA<byte8_t>(35);
		   A->generatedData(10, 1000);

		   //Зберігаю у структурі вказівник на масив
		   D = A->getData();

		   //Виводжу данні
		   pr->print();
		   \endcode
		 */
		virtual void print() = 0;
	};

	/* ****+/^^^/+++++-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+++++/^^^/+**** *
	 * #*****+/^^^/+++++-/+/-+-+                         +-+-/+/-+++++/^^^/+*****# *
	 * #*-*%*-*+                                                         +*-*%*-*# *
	 * %%%%%                      $-------------------$                      %%%%% *
	 * -->                           ALGOR_EXCEPTION                           <-- *
	 * %%%%%                      $-------------------$                      %%%%% *
	 * #*-*%*-*+                                                         +*-*%*-*# *
	 * #*****+/^^^/+++++-/+/-+-+                         +-+-/+/-+++++/^^^/+*****# *
	 * ****+/^^^/+++++-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+++++/^^^/+**** */

	/*!
	  \namespace ALGOR::EXCEPTION_SET
	  \brief Простір імен, що реалізовує виключення
	  \details Простір імен являє собою набір класів, які використовуються при киданні
	  виключень, так як зберігають необхідну інформацію про випадок, що стався. Головний
	  клас \a Exception являє собою каркас винятка, який можна успадкувати для
	  полегшення роботи з винятками. Можна дати додаткову інформацію до вже реалізованих
	  класів-нащадків, а можна створити власні класи-нащадки.
	  \since v0.1.3.0 commit 2cdff0
	 */
	namespace EXCEPTION_SET
	{
		/*!
		   \class Exception
		   \brief Клас-каркас для роботи з винятками
		   \details Клас, що зберігає данні про виняток (номер винятка, деталі та
		   пояснення). Щоб створити об'єкт винятку достатньо переадти необхідні данні
		   конструктору, а для отримання інформації про виняток треба його перехопити
		   і використати метод, що повертає необхідні данні.
		   \since v0.1.1.0 commit c62e85
		   \paragraph Приклад
		   \code{.cpp}
		   try
		   {
			   throw EXCEPTION_SET::Exception(55, "details", "explanation");
		   }
		   catch (EXCEPTION_SET::Exception ex)
		   {
			   cout << "Code: " << ex.code() << ";\n" << ex.what() << "\n-> " << ex.why() << "\n";
		   }
		   //print:
		   //  Code: 55;
		   //  details
		   //  -> explanation
		   \endcode
		   \paragraph Реалізація
		 */
		class Exception
		{
		public:
			/*!
			   \fn Exception(ubit16_t CODE, const byte1_t *DETAILS, const byte1_t *EXPLANATION)
			   \brief Розширений конструктор класу винятків
			   \details Конструктор, що приймає розширену кількість данних, а саме код
			   винятку, деталі винятку, та пояснення до деталей, що не завжди буває
			   необхідним.
			   \param[in] CODE Код Exception
			   \param[in] DETAILS Деталі Exception
			   \param[in] EXPLANATION Пояснення Exception
			   \since v0.1.3.0 commit 2c6408
			   \remark Цей конструктор є розширеним так як дозволяє успадкованим класам
			   надати пояснення до винятку, коли це необхідно, що робить цей клас
			   більш універсальним.
			   \paragraph Приклад
			   \code{.cpp}
			   throw EXCEPTION_SET::Exception(100, "details", "explanation");
			   \endcode
			   \paragraph Реалізація
			 */
			Exception(ubit16_t CODE, const byte1_t *DETAILS, const byte1_t *EXPLANATION);
			/*!
			   \fn Exception(ubit16_t CODE, const byte1_t *DETAILS)
			   \brief Стандартний конструктор класу винятків
			   \details Конструктор, що приймає базову кількість данних про виняток.
			   Зазвичай номеру та деталей помилки буває достатньо.
			   \param[in] CODE Код Exception
			   \param[in] DETAILS Деталі Exception
			   \since v0.1.1.0 commit c62e85
			   \paragraph Приклад
			   \code{.cpp}
			   throw EXCEPTION_SET::Exception(100, "details");
			   \endcode
			   \paragraph Реалізація
			 */
			Exception(ubit16_t CODE, const byte1_t *DETAILS);
			/*!
			   \fn Exception(ubit16_t CODE)
			   \brief Скорочений кодовий конструктор класу винятків
			   \details Конструктор, що приймає скорочену кількість данних про
			   виняток. Єдині данні, що зберігаються у об'єкті винятку, це номер
			   винятку.
			   \param[in] CODE Код Exception
			   \since v0.1.1.0 commit c62e85
			   \paragraph Приклад
			   \code{.cpp}
			   throw EXCEPTION_SET::Exception(100);
			   \endcode
			   \paragraph Реалізація
			 */
			Exception(ubit16_t CODE);
			/*!
			   \fn Exception(const byte1_t *DETAILS)
			   \brief Скорочений детальний конструктор класу винятків
			   \details Конструктор, що приймає скорочену кількість данних про
			   виняток. Єдині данні, що зберігаються у об'єкті винятку, це деталі
			   винятку.
			   \param[in] DETAILS Деталі Exception
			   \since v0.1.1.0 commit c62e85
			   \paragraph Приклад
			   \code{.cpp}
			   throw EXCEPTION_SET::Exception("details");
			   \endcode
			   \paragraph Реалізація
			 */
			Exception(const byte1_t *DETAILS);
			/*!
			   \fn code()
			   \brief Метод, що повідомляє номер винятку
			   \details Повертає номер винятку, що зберігається в об'єкті.
			   \since v0.1.1.0 commit c62e85
			   \retval CODE - номер винятку
			   \paragraph Приклад
			   \code{.cpp}
			   catch (EXCEPTION_SET::Exception ex)
			   {
				   cout << ex.code() << "\n"; //print 100
			   }
			   \endcode
			   \paragraph Реалізація
			 */
			ubit16_t code();
			/*!
			   \fn what()
			   \brief Метод, що повідомляє деталі винятку
			   \details Повертає деталі винятку, що зберігаються в об'єкті.
			   \since v0.1.1.0 commit c62e85
			   \retval DETAILS - деталі винятку
			   \paragraph Приклад
			   \code{.cpp}
			   catch (EXCEPTION_SET::Exception ex)
			   {
				   cout << ex.what() << "\n"; //print "details"
			   }
			   \endcode
			   \paragraph Реалізація
			 */
			const byte1_t *what();
			/*!
			   \fn why()
			   \brief Метод, що дає пояснення винятку
			   \details Повертає пояснення винятку, що зберігається в об'єкті.
			   \since v0.1.3.0 commit 2c6408
			   \retval EXPLANATION - пояснення винятку
			   \paragraph Приклад
			   \code{.cpp}
			   catch (EXCEPTION_SET::Exception ex)
			   {
				   cout << ex.why() << "\n"; //print "explanation"
			   }
			   \endcode
			   \paragraph Реалізація
			 */
			const byte1_t *why();

		protected:
			/*!
			   \var CODE
			   \brief Номер винятку
			   \since v0.1.1.0 commit c62e85
			 */
			ubit16_t CODE;
			/*!
			   \var DETAILS
			   \brief Деталі винятку
			   \since v0.1.1.0 commit c62e85
			 */
			const byte1_t *DETAILS;
			/*!
			   \var EXPLANATION
			   \brief Пояснення винятку
			   \since v0.1.3.0 commit 2c6408
			 */
			const byte1_t *EXPLANATION;
		};

		/*!
		   \var excep55
		   \brief Повідомлення для memory_overflow
		   \since v0.1.3.0 commit d66e53
		   \paragraph Текст повідомлення
		   <em>"Комірка пам'яті, в якій зберігається розмір обсягу даних, більше
		   не може зберігати більше. Ця помилка може виникнути у випадках, коли
		   в комірку, яка може зберігати змінну 0xffffffff, потрібно записати
		   більше значення, тобто більше 4 байт, оскільки клітинка зберігання
		   даних займає 4 байти"</em>
		 */
		const byte1_t excep55[] = "The memory cell that stores the size of the data volume can no longer store more. This error can occur in cases when a larger value is required to be written to the cell that can store the variable 0xffffffff, i.e. more than 4 bytes, since the data size storage cell occupies 4 bytes";
		/*!
		   \var excep101
		   \brief Повідомлення для division_by_zero
		   \since v0.1.3.0 commit d66e53
		   \paragraph Текст повідомлення
		   <em>"Відбулося ділення на нуль - невизначений результат виконання
		   програми"</em>
		 */
		const byte1_t excep101[] = "A division by zero has occurred - an undefined result of the program execution";
		/*!
		   \var excep254
		   \brief Повідомлення для position_failure
		   \since v0.1.3.0 commit d66e53
		   \paragraph Текст повідомлення
		   <em>"Помилка позиції – позиція відсутня в масиві"</em>
		 */
		const byte1_t excep254[] = "Position failure - position is missing in the array";
		/*!
		   \var excep255
		   \brief Повідомлення для value_failure
		   \since v0.1.3.0 commit d66e53
		   \paragraph Текст повідомлення
		   <em>"Помилка значення - значення відсутнє в масиві"</em>
		 */
		const byte1_t excep255[] = "Value failure - value is missing in the array";
		/*!
		   \var excep256
		   \brief Повідомлення для size_failure
		   \since v0.1.3.0 commit d66e53
		   \paragraph Текст повідомлення
		   <em>"Помилка розміру - помилка зміни розміру; наприклад, це може
		   статися, коли розміри збігаються, коли розмір масиву змінюється, або
		   новий розмір більше/менше за межі розмірів"</em>
		 */
		const byte1_t excep256[] = "Size failure - resizing error; for example, it can occur when the sizes match when the array is resized, or the new size is greater/less than limits sizes";
		/*!
		   \var excep400
		   \brief Повідомлення для void_data
		   \since v0.1.3.0 commit d66e53
		   \paragraph Текст повідомлення
		   <em>"Отримано порожню структуру даних"</em>
		 */
		const byte1_t excep400[] = "Geted empty data structure";
		/*!
		   \var excep404
		   \brief Повідомлення для not_found
		   \since v0.1.3.0 commit d66e53
		   \paragraph Текст повідомлення
		   <em>"Помилка пошуку - елемент не знайдено"</em>
		 */
		const byte1_t excep404[] = "Search error - item not found";

		/*!
		   \class memory_overflow
		   \brief Клас-виняток \a "memory_overflow"
		   \details Базовий виняток \a memory_overflow (переповнення пам'яті).
		   Використовує повідомлення EXCEPTION_SET::excep55 та має номер \a 55.
		   \since v0.1.1.0 commit bce6b6
		   \remark Де-які методи при киданні винятку \a 55 можуть давати пояснення.
		 */
		class memory_overflow : public Exception
		{
		public:
			/*!
			   \fn memory_overflow()
			   \brief Виняток memory_overflow
			   \details Конструктор об'єкту, що використовується, як виняток
			   memory_overflow. До каркасу передаються код виключення та деталі.
			   \since v0.1.1.0 commit bce6b6
			   \paragraph Приклад
			   \code{.cpp}
			   throw EXCEPTION_SET::memory_overflow();
			   \endcode
			   \paragraph Реалізація
			 */
			memory_overflow();
			/*!
			   \fn memory_overflow(const byte1_t *explanation)
			   \brief Виняток memory_overflow з поясненням
			   \details Конструктор об'єкту, що використовується, як виняток
			   memory_overflow. До каркасу передаються код виключення, деталі
			   та пояснення.
			   \param[in] explanation Пояснення до деталей винятку
			   \since v0.1.3.0 commit 2с6408
			   \paragraph Приклад
			   \code{.cpp}
			   throw EXCEPTION_SET::memory_overflow("explanation");
			   \endcode
			   \paragraph Реалізація
			 */
			memory_overflow(const byte1_t *explanation);
		};

		/*!
		   \class division_by_zero
		   \brief Клас-виняток \a "division_by_zero"
		   \details Базовий виняток \a division_by_zero (ділення на нуль).
		   Використовує повідомлення EXCEPTION_SET::excep101 та має номер \a 101.
		   \since v0.1.2.0 commit d74cc1
		 */
		class division_by_zero : public Exception
		{
		public:
			/*!
			   \fn division_by_zero()
			   \brief Виняток division_by_zero
			   \details Конструктор об'єкту, що використовується, як виняток
			   division_by_zero. До каркасу передаються код виключення та деталі.
			   \since v0.1.2.0 commit d74cc1
			   \paragraph Приклад
			   \code{.cpp}
			   throw EXCEPTION_SET::division_by_zero();
			   \endcode
			   \paragraph Реалізація
			 */
			division_by_zero();
			/*!
			   \fn division_by_zero(const byte1_t *explanation)
			   \brief Виняток division_by_zero з поясненням
			   \details Конструктор об'єкту, що використовується, як виняток
			   division_by_zero. До каркасу передаються код виключення, деталі
			   та пояснення.
			   \param[in] explanation Пояснення до деталей винятку
			   \since v0.1.3.0 commit 2с6408
			   \paragraph Приклад
			   \code{.cpp}
			   throw EXCEPTION_SET::division_by_zero("explanation");
			   \endcode
			   \paragraph Реалізація
			 */
			division_by_zero(const byte1_t *explanation);
		};

		/*!
		   \class position_failure
		   \brief Клас-виняток \a "position_failure"
		   \details Базовий виняток \a position_failure (збій положення).
		   Використовує повідомлення EXCEPTION_SET::excep254 та має номер \a 254.
		   \since v0.1.1.0 commit 8bbf75
		 */
		class position_failure : public Exception
		{
		public:
			/*!
			   \fn position_failure()
			   \brief Виняток position_failure
			   \details Конструктор об'єкту, що використовується, як виняток
			   position_failure. До каркасу передаються код виключення та деталі.
			   \since v0.1.1.0 commit 8bbf75
			   \paragraph Приклад
			   \code{.cpp}
			   throw EXCEPTION_SET::position_failure();
			   \endcode
			   \paragraph Реалізація
			 */
			position_failure();
			/*!
			   \fn position_failure(const byte1_t *explanation)
			   \brief Виняток position_failure з поясненням
			   \details Конструктор об'єкту, що використовується, як виняток
			   position_failure. До каркасу передаються код виключення, деталі
			   та пояснення.
			   \param[in] explanation Пояснення до деталей винятку
			   \since v0.1.3.0 commit 2с6408
			   \paragraph Приклад
			   \code{.cpp}
			   throw EXCEPTION_SET::position_failure("explanation");
			   \endcode
			   \paragraph Реалізація
			 */
			position_failure(const byte1_t *explanation);
		};

		/*!
		   \class value_failure
		   \brief Клас-виняток \a "value_failure"
		   \details Базовий виняток \a value_failure (збій значення).
		   Використовує повідомлення EXCEPTION_SET::excep255 та має номер \a 255.
		   \since v0.1.1.0 commit 8bbf75
		 */
		class value_failure : public Exception
		{
		public:
			/*!
			   \fn value_failure()
			   \brief Виняток value_failure
			   \details Конструктор об'єкту, що використовується, як виняток
			   value_failure. До каркасу передаються код виключення та деталі.
			   \since v0.1.1.0 commit 8bbf75
			   \paragraph Приклад
			   \code{.cpp}
			   throw EXCEPTION_SET::value_failure();
			   \endcode
			   \paragraph Реалізація
			 */
			value_failure();
			/*!
			   \fn value_failure(const byte1_t *explanation)
			   \brief Виняток value_failure з поясненням
			   \details Конструктор об'єкту, що використовується, як виняток
			   value_failure. До каркасу передаються код виключення, деталі
			   та пояснення.
			   \param[in] explanation Пояснення до деталей винятку
			   \since v0.1.3.0 commit 2с6408
			   \paragraph Приклад
			   \code{.cpp}
			   throw EXCEPTION_SET::value_failure("explanation");
			   \endcode
			   \paragraph Реалізація
			 */
			value_failure(const byte1_t *explanation);
		};

		/*!
		   \class size_failure
		   \brief Клас-виняток \a "size_failure"
		   \details Базовий виняток \a size_failure (збій розміру).
		   Використовує повідомлення EXCEPTION_SET::excep256 та має номер \a 256.
		   \since v0.1.3.0 commit 2c6408
		 */
		class size_failure : public Exception
		{
		public:
			/*!
			   \fn size_failure()
			   \brief Виняток size_failure
			   \details Конструктор об'єкту, що використовується, як виняток
			   size_failure. До каркасу передаються код виключення та деталі.
			   \since v0.1.3.0 commit 2c6408
			   \paragraph Приклад
			   \code{.cpp}
			   throw EXCEPTION_SET::size_failure();
			   \endcode
			   \paragraph Реалізація
			 */
			size_failure();
			/*!
			   \fn size_failure(const byte1_t *explanation)
			   \brief Виняток size_failure з поясненням
			   \details Конструктор об'єкту, що використовується, як виняток
			   size_failure. До каркасу передаються код виключення, деталі
			   та пояснення.
			   \param[in] explanation Пояснення до деталей винятку
			   \since v0.1.3.0 commit 2с6408
			   \paragraph Приклад
			   \code{.cpp}
			   throw EXCEPTION_SET::size_failure("explanation");
			   \endcode
			   \paragraph Реалізація
			 */
			size_failure(const byte1_t *explanation);
		};

		/*!
		   \class void_data
		   \brief Клас-виняток \a "void_data"
		   \details Базовий виняток \a void_data (недійсні дані).
		   Використовує повідомлення EXCEPTION_SET::excep400 та має номер \a 400.
		   \since v0.1.1.0 commit c62e85
		 */
		class void_data : public Exception
		{
		public:
			/*!
			   \fn void_data()
			   \brief Виняток void_data
			   \details Конструктор об'єкту, що використовується, як виняток
			   void_data. До каркасу передаються код виключення та деталі.
			   \since v0.1.1.0 commit c62e85
			   \paragraph Приклад
			   \code{.cpp}
			   throw EXCEPTION_SET::void_data();
			   \endcode
			   \paragraph Реалізація
			 */
			void_data();
			/*!
			   \fn void_data(const byte1_t *explanation)
			   \brief Виняток void_data з поясненням
			   \details Конструктор об'єкту, що використовується, як виняток
			   void_data. До каркасу передаються код виключення, деталі
			   та пояснення.
			   \param[in] explanation Пояснення до деталей винятку
			   \since v0.1.3.0 commit 2с6408
			   \paragraph Приклад
			   \code{.cpp}
			   throw EXCEPTION_SET::void_data("explanation");
			   \endcode
			   \paragraph Реалізація
			 */
			void_data(const byte1_t *explanation);
		};

		/*!
		   \class not_found
		   \brief Клас-виняток \a "not_found"
		   \details Базовий виняток \a not_found (не знайдено).
		   Використовує повідомлення EXCEPTION_SET::excep404 та має номер \a 404.
		   \since v0.1.1.0 commit c62e85
		 */
		class not_found : public Exception
		{
		public:
			/*!
			   \fn not_found()
			   \brief Виняток not_found
			   \details Конструктор об'єкту, що використовується, як виняток
			   not_found. До каркасу передаються код виключення та деталі.
			   \since v0.1.1.0 commit c62e85
			   \paragraph Приклад
			   \code{.cpp}
			   throw EXCEPTION_SET::not_found();
			   \endcode
			   \paragraph Реалізація
			 */
			not_found();
			/*!
			   \fn not_found(const byte1_t *explanation)
			   \brief Виняток not_found з поясненням
			   \details Конструктор об'єкту, що використовується, як виняток
			   not_found. До каркасу передаються код виключення, деталі
			   та пояснення.
			   \param[in] explanation Пояснення до деталей винятку
			   \since v0.1.3.0 commit 2с6408
			   \paragraph Приклад
			   \code{.cpp}
			   throw EXCEPTION_SET::not_found("explanation");
			   \endcode
			   \paragraph Реалізація
			 */
			not_found(const byte1_t *explanation);
		};
	}

	/* ****+/^^^/+++++-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+++++/^^^/+**** *
	 * #*****+/^^^/+++++-/+/-+-+                         +-+-/+/-+++++/^^^/+*****# *
	 * #*-*%*-*+                                                         +*-*%*-*# *
	 * %%%%%                       $------------------$                      %%%%% *
	 * -->                             ALGOR_RANDOM                            <-- *
	 * %%%%%                       $------------------$                      %%%%% *
	 * #*-*%*-*+                                                         +*-*%*-*# *
	 * #*****+/^^^/+++++-/+/-+-+                         +-+-/+/-+++++/^^^/+*****# *
	 * ****+/^^^/+++++-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+++++/^^^/+**** */

	/*!
	  \namespace ALGOR::RANDOM
	  \brief Простір імен, що реалізовує ГПВЧ
	  \details Простір імен являє собою набір класів, які використовуються при
	  Генерації ПсевдоВипадкових Чисел (ГПВЧ). Класи є реалізаціями математичних
	  моделей. Зазвичай використовуються при генерації структур даних, таких як
	  масиви тощо.
	  \since v0.1.3.0 commit d66e53
	 */
	namespace RANDOM
	{
		/*!
		   \class LCM
		   \brief ГПВЧ Лінійний Конґруентний Метод
		   \details Один з найпростіших ГПВЧ. Працює за принципом розрахунку
		   наступного числа. Представляється формулою
		   \f[x_n = (a * x_{n-1} + c) mod(m)\f], де \f$a, c, m\f$ - константні
		   коефіціенти.
		   \since v0.1.3.0 commit ca0704
		   \remark LCM = LinearCongruentMethod
		   \paragraph Ресурси
		   Source: https://en.wikipedia.org/wiki/Linear_congruential_generator\n
		   Paragraph: Parameters in common use\n
		   Table row: MMIX by Donald Knuth\n
		   \paragraph Приклад
		   \code{.cpp}
		   RANDOM::LCM r(getMemoryCell());
		   cout << r.rand() << "\n"; //print 510610997
		   \endcode
		 */
		class LCM
		{
		public:
			/*!
			   \fn LCM(memcell_t seed)
			   \brief Конструктор класу, що приймає сі́м'я
			   \details Конструктор, що приймає сі́м'я ГПВЧ, що є першим числом
			   послідовності, що генерується (\f$x_0\f$). Являє собою аналог
			   стандартної функції \a srand().
			   \param[in] seed
			   \since v0.1.3.0 commit ca0704
			   \paragraph Приклад
			   \code{.cpp}
			   RANDOM::LCM r(getMemoryCell());
			   \endcode
			   або \n
			   \code{.cpp}
			   RANDOM::LCM r(time(NULL));
			   \endcode
			   \paragraph Реалізація
			 */
			LCM(memcell_t seed);
			/*!
			   \fn rand()
			   \brief Метод генерації псевдовипадкового числа
			   \details Алгоритм, що генерує (\a розраховує) наступне число
			   послідовності.
			   \since v0.1.3.0 commit ca0704
			   \retval seed - наступне число послідновності \f$x_n\f$
			   \paragraph Приклад
			   \code{.cpp}
			   cout << r.rand() << "\n"; //print 510610997
			   \endcode
			   \paragraph Реалізація
			 */
			ubit32_t rand();

		private:
			/*!
			   \var a
			   \brief Перше константне число \f$a\f$
			   \details Константа \f$a\f$ = 6'364'136'223'846'793'005.
			   \since v0.1.3.0 commit ca0704
			 */
			const ubit64_t a = 0x5851f42d4c957f2d;
			/*!
			   \var c
			   \brief Перше константне число \f$c\f$
			   \details Константа \f$c\f$ = 1'442'695'040'888'963'407.
			   \since v0.1.3.0 commit ca0704
			 */
			const ubit64_t c = 0x14057b7ef767814f;
			/*!
			   \var m
			   \brief Перше константне число \f$m\f$
			   \details Константа \f$m\f$ = 18'446'744'073'709'551'615.
			   \since v0.1.3.0 commit ca0704
			 */
			const ubit64_t m = 0xffffffffffffffff;
			/*!
			   \var seed
			   \brief Сі́м'я послідовності \f$x_0\f$
			   \details Число, що задає початок послідовності, що генерується.
			   \since v0.1.3.0 commit ca0704
			 */
			memcell_t seed;
		};

		/*!
		   \class RC4
		   \brief Простий криптостійкий генератор
		   \details RC4 — потоковий шифр, розроблений Роном Рівестом
		   (анг. Ron Rivest) у 1987 році.
		   \since v0.1.0.0 commit 88415c
		   \note Може генерувати значення лише у діапазоні 0-255 (1 байт).
		   \deprecated На даному етапі розробка даного ГВЧ заморожена. Алгоритм
		   застарів. З часом можливе його повне видалення, чи повна модернізація,
		   чому не радиться його використовувати.
		   \paragraph Ресурси
		   Source: https://www.youtube.com/watch?v=PQlZI-QoM2A\n
		   \paragraph Приклад
		   \code{.cpp}
		   RC4 rc4;							//Створюю об'єкт ГВЧ
		   char key[100];						//Створюю ключ
		   rc4.crypto_srand(key, 100);			//Встановлюю ключ
		   int BUFSIZe = 100;
		   char output[BUFSIZe];				//Створюю масив під результат
		   rc4.crypto_rand(output, BUFSIZe);	//Генерую результат
		   \endcode
		*/
		class RC4
		{
		public:
			/*!
			   \fn crypto_srand(const byte1_t *key, byte4_t ksize)
			   \brief Встановлює ключ генерації
			   \details Приймає ключ і розраховує з нього ключ генерації
			   \param[in] key Ключ, що встановлюється
			   \param[in] ksize Розмір ключа
			   \since v0.1.0.0 commit 88415c
			   \paragraph Приклад
			   \code{.cpp}
			   RC4 rc4;					//Створюю об'єкт ГВЧ
			   char key[100];				//Створюю ключ
			   rc4.crypto_srand(key, 100);	//Встановлюю ключ
			   \endcode
			   \paragraph Реалізація
			 */
			void crypto_srand(const byte1_t *key, byte4_t ksize);
			/*!
			   \fn crypto_rand(byte1_t *output, byte4_t size)
			   \brief Генерує значення
			   \details Генерує масив вихідних зашифрованих значень, які можна
			   використовувати, як згенеровані ГВЧ.
			   \param[out] output Генерує масив вихідних елементів
			   \param size Розмір масиву вихідних елементів
			   \since v0.1.0.0 commit 88415c
			   \paragraph Приклад
			   \code{.cpp}
			   int BUFSIZe = 100;
			   char output[BUFSIZe];				//Створюю масив під результат
			   rc4.crypto_rand(output, BUFSIZe);	//Генерую результат
			   \endcode
			   \paragraph Реалізація
			 */
			void crypto_rand(byte1_t *output, byte4_t size);

		private:
			/*!
			   \var Sbox
			   \brief Ключ генерації
			   \since v0.1.0.0 commit 88415c
			 */
			ubit8_t Sbox[256];
		};

		/*!
		   \class MersenneTwister
		   \brief Складний ГПВЧ, що базується на властивостях простих чисел Мерсенна
		   \details Вихор Мерсенна — ГПВЧ, розроблений у 1997 році японськими
		   вченими Макото Мацумото та Такудзі Нісімурою. Вихор Мерсенна ґрунтується
		   на властивостях простих чисел Мерсенна та забезпечує швидке генерування
		   високоякісних за критерієм випадковості псевдовипадкових чисел.
		   \since v0.1.0.0 commit 88415c
		   \deprecated На даному етапі розробка даного ГВЧ заморожена. Нехай
		   він і краще за Лінійні ГПВЧ, його ще не доведено до відлагодженого стану.
		   Його ще й досі складно використовувати. У майбутньому можлива повна
		   зміна сигнатур методів у класі. Чи його повне видалення.
		   \paragraph Ресурси
		   Source: https://www.agner.org/random/\n
		   \paragraph Приклад
		   \code{.cpp}
		   //Створюю об'єкт ГВЧ
		   using namespace ALGOR::RANDOM;

		   MersenneTwister RanGen(getMemoryCell(32));

		   //Заповнюю масив числами від 10 до 100
		   for (asize_t i = 0; i < array_size; i++)
		   {
			   array[i] = RanGen.IRandom(10, 100);
		   }
		   \endcode
		 */
		class MersenneTwister
		{
		public:
			/*!
			   \fn MersenneTwister(byte4_t seed)
			   \brief Конструктор класу ГПВЧ Вихор Марсенна (встановлює сі́м'я)
			   \details Встановлює сі́м'я та проводить ініціалізацію послідовності,
			   що буде генеруватися.
			   \param[in] seed Сі́м'я генерації
			   \since v0.1.0.0 commit 88415c
			   \paragraph Приклад
			   \code{.cpp}
			   MersenneTwister RanGen(getMemoryCell(32));
			   \endcode
			   \paragraph Реалізація
			 */
			MersenneTwister(byte4_t seed);
			/*!
			   \fn RandomInit(byte4_t seed)
			   \brief Ініціалізація ГПВЧ
			   \details Використовується при перевстановленні семені ГПВЧ.
			   \param[in] seed Сі́м'я генерації
			   \since v0.1.0.0 commit 88415c
			   \paragraph Приклад
			   \code{.cpp}
			   RanGen.RandomInit(getMemoryCell(32));
			   \endcode
			   \paragraph Реалізація
			 */
			void RandomInit(byte4_t seed);
			/*!
			   \fn rand()
			   \brief Метод генеації даних на усьому можливому діапазоні
			   \details Генерує числа на увесь можливий діапазон змінної. Цей метод
			   спеціально було створено під сумісність з функцією тестування ГПВЧ.
			   \since v0.1.3.0 commit ca0704
			   \warning Цей метод було написано лише для функції тестування ГПВЧ. Не
			   використовуйте його, якщо у вас є обмеження на число, що має бути
			   згенероване. Для цього використовуйте метод
			   MersenneTwister::IRandom, що спеціально для цього й створювався.
			   \warning А також, якщо Вам потрібно згенерувати число на усьому
			   діапазоні, то краще використати MersenneTwister::BRandom, щоб уникнути
			   додаткових розрахунків.
			   \deprecated Буде видалено після завершення тестування ГПВЧ
			   \return згенероване число
			   \paragraph Реалізація
			 */
			sbit32_t rand();
			/*!
			   \fn IRandom(byte4_t min, byte4_t max)
			   \brief Метод генерація числа у заданому діапазоні
			   \details Генерує число у заданому діапазоні.
			   \param[in] min Мінімальне число діапазону
			   \param[in] max Максимальне число діапазону
			   \since v0.1.0.0 commit 88415c
			   \return згенероване число у заданому діапазоні
			   \paragraph Приклад
			   \code{.cpp}
			   array[0] = RanGen.IRandom(10, 100);
			   \endcode
			   \paragraph Реалізація
			 */
			byte4_t IRandom(byte4_t min, byte4_t max);
			/*!
			   \fn IRandomX(byte4_t min, byte4_t max)
			   \brief Більш точніший метод генерація числа у заданому діапазоні
			   \details Є аналогом методу MersenneTwister::IRandom, що генерує
			   число за складнішим алгоритмом, а саме число є більш точнішим.
			   \param[in] min Мінімальне число діапазону
			   \param[in] max Максимальне число діапазону
			   \since v0.1.0.0 commit 88415c
			   \return точне згенероване число у заданому діапазоні
			   \paragraph Приклад
			   \code{.cpp}
			   array[0] = RanGen.IRandomX(10, 100);
			   \endcode
			   \paragraph Реалізація
			 */
			byte4_t IRandomX(byte4_t min, byte4_t max);
			/*!
			   \fn Random()
			   \brief Метод генеріції числа з плаваючою комою
			   \details Генерує числа з плаваючою комою
			   \since v0.1.0.0 commit 88415c
			   \warning Цей метод генерує числа від 0 до 1, тобто всі
			   згенеровані числа будуть меншими від одиниці
			   \return число з плаваючою комою
			   \paragraph Приклад
			   \code{.cpp}
			   array[0] = RanGen.Random();
			   \endcode
			   \paragraph Реалізація
			 */
			fbit64_t Random();
			/*!
			   \fn BRandom()
			   \brief Метод генерації випадкових бітів
			   \details Генерує випадкові біти у змінній з чотирьох байт, що дозволяє
			   згенерувати 32-бітове число на всьому діапазоні.
			   \since v0.1.0.0 commit 88415c
			   \note Може слугувати аналогом методу MersenneTwister::rand, але той
			   метод є надстройкою над MersenneTwister::IRandom для функції тестування
			   ГПВЧ, що викликає додаткові розрахунки та витрати ресурсів. Якщо
			   потрібно відразу згенерувати якесь число на усьому діапазоні, то краще
			   обирати цей метод.
			   \return згенероване число на всьому діапазоні
			   \paragraph Приклад
			   \code{.cpp}
			   array[0] = RanGen.BRandom();
			   \endcode
			   \paragraph Реалізація
			 */
			ubit32_t BRandom();

		private:
			/*!
			   \fn Init0(byte4_t seed)
			   \brief Базова процедура ініціалізації
			   \param[in] seed Сі́м'я генерації
			   \since v0.1.0.0 commit 88415c
			   \paragraph Реалізація
			 */
			void Init0(byte4_t seed);
			/*!
			   \var mersenne_twister[624]
			   \brief Вектор стану
			   \since v0.1.0.0 commit 88415c
			 */
			ubit32_t mersenne_twister[624];
			/*!
			   \var mersenne_twister_index
			   \brief Індекс у векторі стану (MersenneTwister::mersenne_twister)
			   \since v0.1.0.0 commit 88415c
			 */
			byte4_t mersenne_twister_index;
			/*!
			   \var LastInterval
			   \brief Довжина останнього інтервалу для MersenneTwister::IRandomX
			   \since v0.1.0.0 commit 88415c
			 */
			ubit32_t LastInterval;
			/*!
			   \var RejectionLimit
			   \brief Ліміт відхилень, який використовує MersenneTwister::IRandomX
			   \since v0.1.0.0 commit 88415c
			 */
			ubit32_t RejectionLimit;
		};

		/*!
		   \fn tester(ubit32_t left_limit, ubit32_t right_limit)
		   \brief Функція тестування ГПВЧ на рівномірність
		   \details Тестує ГПВЧ на рівномірність генерації чисел, використовуючи
		   коефіціент узгодженості Пірсона.
		   \tparam Generator Клас алгоритму ГПВЧ, що потрібно протестувати.
		   \param[in] left_limit Мінімальне число діапазону генерації
		   при тестуванні
		   \param[in] right_limit Максимальне число діапазону генерації
		   при тестуванні
		   \since v0.1.1.4 commit ca0704
		   \warning ГВЧ RANDOM::RC4 поки не можна протестувати, так як його не
		   підготовлено до використання данною функцією тестування, та й сама
		   функція не компілюється під цей алгоритм.
		   \return коефіціент узгодженості Пірсона
		   \paragraph Приклад
		   \code{.cpp}
		   cout << RANDOM::tester<RANDOM::LCM>(0, 999999) << "\n";
		   cout << RANDOM::tester<RANDOM::MersenneTwister>(0, 999999) << "\n";
		   //print 98.2674
		   //print 109.996
		   \endcode
		   \remark Як можна побачити з прикладу, RANDOM::LCM генерує
		   числа більш рівномірно. Однак це не значить, що він є кращим... Як вже
		   було сказано, ГПВЧ Вихор Марсена є швидшим <del>(хоча й використовує
		   набагато більше операцій та розрахунків)</del> та якіснішим. А отримані
		   результати є лише випадковістю. Інколи краще генерує RANDOM::LCM, а
		   інколи RANDOM::MersenneTwister, через що можна зробити висновок, що вони
		   однаково якісно генерують числа <del>(чи може просто добре підібрані
		   коефіціенти для RANDOM::LCM)</del>. Для функції генерації
		   ALGOR::generate_struct структури масиву ALGOR::Array все ж таки було
		   обрано RANDOM::LCM, так як він набагато легший у реалізації та
		   розумінні, а працює так само якісно, як і RANDOM::MersenneTwister.
		   \paragraph Реалізація
		 */
		template <class Generator>
		fbit64_t tester(ubit32_t left_limit, ubit32_t right_limit);
	}

	/* ****+/^^^/+++++-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+++++/^^^/+**** *
	 * #*****+/^^^/+++++-/+/-+-+                         +-+-/+/-+++++/^^^/+*****# *
	 * #*-*%*-*+                                                         +*-*%*-*# *
	 * %%%%%                      $-------------------$                      %%%%% *
	 * -->                             ALGOR_ARRAY                             <-- *
	 * %%%%%                      $-------------------$                      %%%%% *
	 * #*-*%*-*+                                                         +*-*%*-*# *
	 * #*****+/^^^/+++++-/+/-+-+                         +-+-/+/-+++++/^^^/+*****# *
	 * ****+/^^^/+++++-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+++++/^^^/+**** */

	///-
	template <typename type_array>
	class ArrayProcessing
	{
	public:
		/*!
		\brief Finds the minimum element in an array by iterating over
		\tparam type_array The type of elements that the array stores. For example int or float
		\param[in] Array The array in which to look for the minimum element
		\param[in] array_size The size of this very array
		\throw void_data Transferred an empty array
		\return type_array
		*/
		static type_array minimum(const type_array *Array, const asize_t &array_size);

		/*!
		\brief Finds the maximum element in an array by iterating over
		\tparam type_array The type of elements that the array stores. For example int or float
		\param[in] Array The array in which to look for the maximum element
		\param[in] array_size The size of this very array
		\throw void_data Transferred an empty array
		\return type_array
		*/
		static type_array maximum(const type_array *Array, const asize_t &array_size);

		///-
		static bool isOrderliness(const type_array *Array, const asize_t &array_size);

		///-
		static asize_t distance(type_array *first, type_array *last);

		///-
		static type_array *lower_bound(type_array *first, type_array *last, const type_array &value);

		///-
		static type_array *upper_bound(type_array *first, type_array *last, const type_array &value);

		/*!
		\brief Adds a specific value to an array at a specified position
		\tparam type_array The type of elements that the array stores. For example int or float
		\param[in, out] Array The array to which the element is added
		\param[in] array_size The size of this very array
		\param[in] value The element to add to the array
		\param[in] position The position at which the element will be added
		*/
		static void addElement(type_array *&Array, asize_t &array_size, const type_array &value, const asize_t position = 0);

		/*!
		\brief Removes the specified position from the array
		\tparam type_array The type of elements that the array stores. For example int or float
		\param[in, out] Array The array in which the position will be deleted
		\param[in] array_size The size of this very array
		\param[in] position The position at which the element will be removed
		*/
		static void subtractElement(type_array *&Array, asize_t &array_size, const asize_t position);

		/*!
		\brief Removes a specific element from all positions in an array
		\tparam type_array The type of elements that the array stores. For example int or float
		\param[in, out] Array An array in which all elements that match the given value will be removed
		\param[in] array_size The size of this very array
		\param[in] value The value to be removed in the entire array
		*/
		static void subtractValue(type_array *&Array, asize_t &array_size, const type_array &value);

		/*!
		\brief Copies an array
		\tparam type_array The type of elements that the array stores. For example int or float
		\param[in, out] new_array The array into which the data is copied
		\param[in] old_array The array from which to copy
		\param[in] size_of_copied A parameter that indicates how many items to copy
		\param[in] position_in_new_array The position from which to start writing in the array to which the data is copied
		\param[in] position_in_old_array The position from which to start reading from the array, from which the data is copied
		*/
		static void copy(type_array *new_array, const type_array *old_array, const asize_t &size_of_copied, asize_t position_in_new_array = 0, asize_t position_in_old_array = 0);
	};

	/*!
	   \struct Array
	   \brief Структура, що імітує масив
	   \details Призначений для зберігання вказівника на динамічний масив та його
	   розмір
	   \tparam type_array Тип елементів, що зберігаються в масиві
	   \since v0.0.1.0 commit 979bf4
	   \warning Структуру можна створити будь-якого типу, але функції та класи
	   підтримують тільки 5 типів: \a byte8_t, \a ubit64_t, \a fbit64_t,
	   \a fbit128_t та \a asize_t. Тому будь-які інші типи можна використовувати
	   тільки тоді, коли дана структура не буде взаємоді'яти з функіоналом
	   бібліотеки, інакше ви зіштовхнетесь з помилкою <em>"undefined reference
	   to"</em>.
	   \paragraph Приклад
	   \code{.cpp}
	   Array<long long> *arr;
	   \endcode
	   \paragraph Реалізація
	 */
	template <typename type_array>
	struct Array
	{
		type_array *array = nullptr;
		asize_t array_size = 0;
	};
	/*!
	   \fn create_struct(const asize_t &SIZE, bool mem_allocation = true)
	   \brief Створює структуру з покажчиком на масив
	   \details Зберігає розмір масиву, виділяє пам'ять під цей самий масив та повертає
	   вказівник на структуру масиву.
	   \tparam type_array Тип елементів, що будуть зберігатися у масиві
	   \param[in] SIZE Розмір створюваного масиву
	   \param[in] mem_allocation Логічний флаг, чи потрібно виділяти пам'ять під масив
	   \retval Array<type_array>* вказівник на створену структуру
	   \since v0.1.0.0 commit 85698d
	   \remark Якщо ви вже виділили пам'ять під масив, то структурі не потрібно повторно
	   виділяти пам'ять. Структура лише зберігає розмір масиву та сам вказівник на цей
	   масив. Тому у цьому випадку флагу \a mem_allocation потрібно передати \a false і
	   після цього зберегти вказівник на масив у структурі. У інших випадках флаг
	   \a mem_allocation краще не змінювати.
	   \paragraph Приклад
	   \code{.cpp}
	   Array<long long> *arr = create_struct<long long>(10); //arr = @0x1a1700
	   \endcode
	   \paragraph Реалізація
	 */
	template <typename type_array>
	Array<type_array> *create_struct(const asize_t &SIZE, bool mem_allocation = true);
	/*!
	   \fn generate_struct(Array<type_array> *&Array, const sbit64_t &min_limit, const sbit64_t &max_limit, const ubit32_t denominator = 1)
	   \brief Генерує випадкові значення у структурі масиву
	   \details Генерує у структурі масиву значення із заданого діапазону. Якщо
	   задати \a denominator, то можна отримати кратні, чи дрібні значення данних.
	   \tparam type_array Вказує якого типу будуть генеруватися числа у структурі
	   масиву
	   \param[in, out] Array Структура масиву, у якій потрібно згенерувати данні
	   \param[in] min_limit Мінімально можливе згенероване значення
	   \param[in] max_limit Максимально можливе згенероване значення
	   \param[in] denominator Дільник для генерації \a float данних
	   \since v0.1.3.0 commit ca0704
	   \paragraph Приклад
	   \code{.cpp}
	   generate_struct(arr, 1, 12); //arr->array = {9 9 7 7 4 7 2 7 2 9}
	   \endcode
	   \paragraph Реалізація
	 */
	template <typename type_array>
	void generate_struct(Array<type_array> *&Array, const sbit64_t &min_limit, const sbit64_t &max_limit, const ubit32_t denominator = 1);
	/*!
	   \fn remove_struct(Array<type_array> *&Array)
	   \brief remove_struct
	   \details Звільняє пам'ять від масиву, що зберігається у структурі й звільняє
	   з пам'яті саму структуру
	   \tparam type_array Тип елементів, що зберігаються у масиві
	   \param[in, out] Array Масив, який потрібно видалити
	   \result Вказівник на структуру після виклику цієї функції буде вказувати на
	   \a nullptr.
	   \since v0.1.0.0 commit 48aa64
	   \paragraph Приклад
	   \code{.cpp}
	   remove_struct(arr); //arr = 0x0
	   \endcode
	   \paragraph Реалізація
	 */
	template <typename type_array>
	void remove_struct(Array<type_array> *&Array);

	/*!
	\brief The base class, which is organized for working with arrays - memory allocation, storage, deletion
	\tparam type_array The type of elements that the array stores. For example int or float
	*/
	template <typename type_array>
	class ArrayBase
	{
	protected:
		/*!
		\brief Construct a new ArrayBase<type_array>::ArrayBase object
		\details With this creation of an object, both the structure and the object of the class will point to the same array
		\tparam type_array The type of elements that the array stores. For example int or float
		\param[in] Array Pointer to a structured array
		*/
		ArrayBase(Array<type_array> *&Array);
		/*!
		\brief Construct a new ArrayBase<type_array>::ArrayBase object
		\details With such an object creation, memory will be allocated for a new array, the pointer to which will be stored only in the class object
		\tparam type_array The type of elements that the array stores. For example int or float
		\param[in] SIZE The size of the array being created
		*/
		ArrayBase(const asize_t &SIZE);
		/*!
		\fn ArrayBase<type_array>::ArrayBase()
		\brief Construct a new ArrayBase<type_array>::ArrayBase object
		\details With this creation of an object, no memory will be allocated for the array. The object will be empty
		\tparam type_array The type of elements that the array stores. For example int or float
		*/
		ArrayBase();

		///-
		void verification(Array<type_array> *Array);

		Array<type_array> *ARRAY = nullptr; ///< Pointer to a structure storing an array
	};

	/*!
	\brief Array processing
	\details This is the main class for working with arrays, the tasks of which
			 are storing a pointer to an array, the ability to create, delete, modify it,
			 calculate characteristics, etc.
	\tparam type_array The type of elements that the array stores. For example int or float
	*/
	template <typename type_array>
	class ARRAYDATA : public ArrayBase<type_array>
	{
	public:
		/*!
		\brief Construct a new arraydata<type array>::arraydata object
		\details With this creation of an object, both the structure and the object of the class will point to the same array. An example of an array object announcement:
		\code
		Array<int> *arr = create_struct(12);
		ARRAYDATA<int> *array = new ARRAYDATA<int>(arr);
		\endcode
		\tparam type_array The type of elements that the array stores. For example int or float
		\param[in] Array Pointer to a structured array
		*/
		ARRAYDATA(Array<type_array> *&Array);
		/*!
		\brief Construct a new arraydata<type array>::arraydata object
		\details With such an object creation, memory will be allocated for a new array, the pointer to which will be stored only in the class object. An example of an array object announcement:
		\code
		ARRAYDATA<int> *array = new ARRAYDATA<int>(12);
		\endcode
		\tparam type_array The type of elements that the array stores. For example int or float
		\param[in] SIZE The size of the array being created
		*/
		ARRAYDATA(const asize_t &SIZE);
		///-
		~ARRAYDATA();

		enum class ArrayType /// A set of array types
		{
			NUMBER, ///< Indicates that the array stores numbers
			STRING	///< Indicates that the array stores strings
		};

		///-
		struct mode : Array<type_array>
		{
			ubit32_t highest_frequency = 0;
		};

		/*!
		\brief A method that fills the entire array with random values
		\code
		array->generatedData(1, 100);
		\endcode
		\tparam type_array The type of elements that the array stores. For example int or float
		\param min_limit The minimum value that can be generated
		\param max_limit The maximum value that can be generated
		*/
		void generatedData(const sbit64_t &min_limit, const sbit64_t &max_limit, const ubit32_t denominator = 1);
		/*!
		\brief A method that replaces the previous array with a new one, freeing memory from the previous one
		\tparam type_array The type of elements that the array stores. For example int or float
		\param Array An array that will replace the previous one in the object
		*/
		void setNewData(Array<type_array> *&Array);
		/*!
		\brief A method that replaces the previous array with a new one without freeing memory from the previous one
		\tparam type_array The type of elements that the array stores. For example int or float
		\param Array An array that will replace the previous one in the object
		*/
		void setData(Array<type_array> *&Array);
		/*!
		\brief Method that replaces the old array by copying the existing one
		\tparam type_array The type of elements that the array stores. For example int or float
		\param CloningArray The array to be copied to the object
		*/
		void cloneData(Array<type_array> *&CloningArray);
		/*!
		\brief Returns a pointer to an array
		\tparam type_array The type of elements that the array stores. For example int or float
		\return Array<type_array>*
		*/
		Array<type_array> *&getData();
		///-
		asize_t getSize();
		///-
		type_array getValue(const asize_t &position);
		/*!
		\brief Linear item search method
		\details Returns all occurrences of the found value
		\tparam type_array The type of elements that the array stores. For example int or float
		\param required_element The value to find
		\return Array<int>*
		*/
		Array<asize_t> *lenear_getPosition(const type_array &required_element);
		/*!
		\brief Binary item search method
		\details Returns only one position and is only used in sorted arrays. It is used to
				 facilitate the programmer's work so that the method does not need to pass a bunch
				 of parameters that are needed in the algorithm, but the launch is always carried
				 out by passing the same values.
		\tparam type_array The type of elements that the array stores. For example int or float
		\param required_element The value to find
		\return int
		*/
		asize_t binary_getPosition(const type_array &required_element);
		/*!
		\brief Optimized method for finding the minimum element
		\tparam type_array The type of elements that the array stores. For example int or float
		\param ArrStat Array status
		\return type_array
		*/
		type_array getMin();
		/*!
		\brief Optimized method for finding the maximum element
		\tparam type_array The type of elements that the array stores. For example int or float
		\param ArrStat Array status
		\return type_array
		*/
		type_array getMax();

		/*!
		\brief The method removes the old array, creates a new one with the same characteristics
			   (size, minimum and maximum limits) and fills it (unlike respawn (), which does
			   not generate elements).
		\tparam type_array The type of elements that the array stores. For example int or float
		*/
		void reset();
		/*!
		\fn void ARRAYDATA<type_array>::resize(const asize_t &NEW_SIZE, const type_array &setElement)
		\brief Method that resizes the array
		\tparam type_array The type of elements that the array stores. For example int or float
		\param NEW_SIZE New array size
		\param setElement The value with which new cells of the array are filled
		\warning In the case of increasing the size of the array after copying,
				 the new cells remain empty and store "garbage" in themselves.
				 Sometimes, by accident, a programmer can try to get data without
				 specifying it, as a result of which, in the best case, an incorrect
				 result will simply be given, and in the worst case, the program may crash.
				 For this, the setElement parameter was created, but it must be specified
				 not only in case of an increase in size, but always when calling the method
				 for prevention. The programmer may not even know the current size
				 of the array, therefore, he cannot know whether the array will
				 be increased or decreased.
		*/
		void resize(const asize_t &NEW_SIZE, const type_array &setElement);
		/*!
		\brief Changes the value at the specified position
		\tparam type_array The type of elements that the array stores. For example int or float
		\param position The position at which the value changes
		\param value The value to be placed in the position
		*/
		void replace(const asize_t &position, const type_array &value);
		/*!
		\brief Reverses the array
		\tparam type_array The type of elements that the array stores. For example int or float
		*/
		void reverse();
		/*!
		\brief The method deletes the old array, however, the memory for the new array
			   is allocated the same size without filling it, unlike reset()
		\tparam type_array The type of elements that the array stores. For example int or float
		*/
		void respawn();

		/*!
		\brief Sequence search method that returns all its occurrences
		\tparam type_array The type of elements that the array stores. For example int or float
		\param SUBARRAY The substring that is searched for in the main array
		\param ArrType Array type
		\return Array<int>*
		*/
		Array<asize_t> *searcherOccurrencesOfSubstring(Array<type_array> *&SUBARRAY, ArrayType ArrType = ArrayType::NUMBER);

		/*!
		\brief Method that returns the arithmetic mean of an array
		\tparam type_array The type of elements that the array stores. For example int or float
		\return type_array
		*/
		type_array average();
		/*!
		\brief Method that returns the median of an array
		\tparam type_array The type of elements that the array stores. For example int or float
		\return type_array
		*/
		type_array mediana();
		/*!
		\brief A method that returns all elements with an array mode
		\tparam type_array The type of elements that the array stores. For example int or float
		\param highest_frequency An indicator of the frequency of occurrence of elements that are most often found
		\return Array<type_array>*
		*/
		mode *moda();

		///-
		bool operator=(Array<type_array> *&cloningArray);
		///-
		bool operator==(Array<type_array> *&anotherArray);
		///-
		Array<type_array> *&operator^=(const asize_t &NewSize);
		/*!
		\brief Operator for increasing an array by a specific size
		\tparam type_array The type of elements that the array stores. For example int or float
		\param addSize Parameter indicating how much to increase the array
		*/
		Array<type_array> *&operator+=(const type_array &addValue);
		/*!
		\brief Operator for decreasing an array by a specific size
		\tparam type_array The type of elements that the array stores. For example int or float
		\param subtractSize Parameter indicating how much to reduce the array
		*/
		Array<type_array> *&operator-=(const type_array &subtractValue);
		/*!
		\brief Operator for increasing an array by several times
		\tparam type_array The type of elements that the array stores. For example int or float
		\param multiplySize Parameter indicating how many times to increase the array
		*/
		Array<type_array> *&operator*=(const type_array &multiplyValue);
		/*!
		\brief Operator for decreasing an array by some times
		\tparam type_array The type of elements that the array stores. For example int or float
		\param divideSize Параметр, указывающий, во сколько раз следует уменьшить массив
		*/
		Array<type_array> *&operator/=(const type_array &divideValue);
		/*!
		\brief Operator adding an element to the end of an array
		\tparam type_array The type of elements that the array stores. For example int or float
		\param value The value to add to the end of the array
		*/
		Array<type_array> *&operator&=(const type_array &value);
		/*!
		\brief An operator that removes all elements with a specified value
		\tparam type_array The type of elements that the array stores. For example int or float
		\param value The value to be removed
		*/
		Array<type_array> *&operator|=(const type_array &value);
		/*!
		\brief Operator that removes an element from the end of an array
		\tparam type_array The type of elements that the array stores. For example int or float
		*/
		Array<type_array> *&operator!();
		/*!
		\brief Operator for merging two arrays in the current object
		\tparam type_array The type of elements that the array stores. For example int or float
		\param appendingArray An array to attach from another object
		*/
		Array<type_array> *&operator<<=(ARRAYDATA<type_array> *&appendingArray);
		/*!
		\brief Operator for merging two arrays in a received object
		\tparam type_array The type of elements that the array stores. For example int or float
		\param appendingArray An array from another object to which the current array will be passed
		*/
		Array<type_array> *&operator>>=(ARRAYDATA<type_array> *&appendingArray);

	private:
		/*!
		\brief Removes an array
		\tparam type_array The type of elements that the array stores. For example int or float
		*/
		void remove();
	};

	/* ****+/^^^/+++++-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+++++/^^^/+**** *
	 * #*****+/^^^/+++++-/+/-+-+                         +-+-/+/-+++++/^^^/+*****# *
	 * #*-*%*-*+                                                         +*-*%*-*# *
	 * %%%%%                      $-------------------$                      %%%%% *
	 * -->                            ALGOR_SORTING                            <-- *
	 * %%%%%                      $-------------------$                      %%%%% *
	 * #*-*%*-*+                                                         +*-*%*-*# *
	 * #*****+/^^^/+++++-/+/-+-+                         +-+-/+/-+++++/^^^/+*****# *
	 * ****+/^^^/+++++-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+++++/^^^/+**** */

	/* ****+/^^^/+++++-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+++++/^^^/+**** *
	 *                      Список нереалізованих алгоритмів:                      *
	 * 1)  ProportionExtendSort		Категорія Exchange_Sorts                       *
	 * 2)  Smooth_Sort				Категорія Selection_Sorts                      *
	 * 3)  CartesianTreeSort		Категорія Selection_Sorts                      *
	 * 4)  TournamentSort			Категорія Selection_Sorts                      *
	 * 5)  WeakHeapSort				Категорія Selection_Sorts                      *
	 * 6)  SplaySort				Категорія Insertion_Sorts                      *
	 * 7)  CascadeMergeSort			Категорія Merge_Sorts                          *
	 * 8)  OscillatingMergeSort		Категорія Merge_Sorts                          *
	 * 9)  PolyphaseMergeSort		Категорія Merge_Sorts                          *
	 * 10) BurstSort				Категорія Distribution_Sorts                   *
	 * 11) ProxmapSort				Категорія Distribution_Sorts                   *
	 * 12) PairwiseSortingNetwork	Категорія Concurrent_Sort                      *
	 * 13) SampleSort				Категорія Concurrent_Sort                      *
	 * 14) BlockMergeSort			Категорія Hybrid_Sorts                         *
	 * 15) KirkpatrickReischSort	Категорія Hybrid_Sorts                         *
	 * 16) IntroSort				Категорія Hybrid_Sorts                         *
	 * 17) SpreadSort				Категорія Hybrid_Sorts                         *
	 * 18) MergeInsertionSort		Категорія Hybrid_Sorts                         *
	 * 19) TopologicalSort			Категорія Other_Sorts                          *
	 * 20) SpaghettiSort			Категорія Other_Sorts                          *
	 * ****+/^^^/+++++-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+++++/^^^/+**** */

	template <typename type_array>
	class Comparative_Sorts : public ArrayBase<type_array>
	{
	public:
		Comparative_Sorts(Array<type_array> *&Array);

		// <<==		Категорія Exchange_Sorts	==>>
		void Bubble_Sort();			 // №	 4	/цілі+ цілі- цілі+- дрібні+ дрібні- дрібні+-
		void Cocktail_Shaker_Sort(); // №	 5	/цілі+ цілі- цілі+- дрібні+ дрібні- дрібні+-
		void Odd_Even_Sort();		 // №	13	/цілі+ цілі- цілі+- дрібні+ дрібні- дрібні+-
		void Comb_Sort();			 // №	 6	/цілі+ цілі- цілі+- дрібні+ дрібні- дрібні+-
		void Gnome_Sort();			 // №	 8	/цілі+ цілі- цілі+- дрібні+ дрібні- дрібні+-
		void Quick_Sort();			 // №	16	/цілі+ цілі- цілі+- дрібні+ дрібні- дрібні+-
		void Slow_Sort();			 // №	19	/цілі+ цілі- цілі+- дрібні+ дрібні- дрібні+-
		void Stooge_Sort();			 // №	20	/цілі+ цілі- цілі+- дрібні+ дрібні- дрібні+-
		void Bogo_Sort();			 // №	 3	/цілі+ цілі- цілі+- дрібні+ дрібні- дрібні+-
		// <<==		Категорія Selection_Sorts	==>>
		void Selection_Sort(); // №	17	/цілі+ цілі- цілі+- дрібні+ дрібні- дрібні+-
		void Heap_Sort();	   // №	 9	/цілі+ цілі- цілі+- дрібні+ дрібні- дрібні+-
		void Cycle_Sort();	   // №	 7	/цілі+ цілі- цілі+- дрібні+ дрібні- дрібні+-
		// <<==		Категорія Insertion_Sorts	==>>
		void Insert_Sort();	  // №	10	/цілі+ цілі- цілі+- дрібні+ дрібні- дрібні+-
		void Shell_Sort();	  // №	18	/цілі+ цілі- цілі+- дрібні+ дрібні- дрібні+-
		void Tree_Sort();	  // №	22	/цілі+ цілі- цілі+- дрібні+ дрібні- дрібні+-
		void Library_Sort();  // №	11	/цілі+ цілі- цілі+- дрібні+ дрібні- дрібні+-
		void Patience_Sort(); // №	15	/цілі+ цілі- цілі+- дрібні+ дрібні- дрібні+-
		// <<==		Категорія Merge_Sorts		==>>
		void Merge_Sort(); // №	12	/цілі+ цілі- цілі+- дрібні+ дрібні- дрібні+-
		// <<==		Категорія Concurrent_Sort	==>>
		void Bitonic_Sorter();			  // №	 2	/цілі+ цілі- цілі+- дрібні+ дрібні- дрібні+-
		void Batcher_OddEven_MergeSort(); // №	 1	/цілі+ цілі- цілі+- дрібні+ дрібні- дрібні+-
		// <<==		Категорія Hybrid_Sorts		==>>
		void Tim_Sort(); // №	21	/цілі+ цілі- цілі+- дрібні+ дрібні- дрібні+-
		// <<==		Категорія Other_Sorts		==>>
		void Pancake_Sort(); // №	14	/цілі+ цілі- цілі+- дрібні+ дрібні- дрібні+-

		// <<==				Classes				==>>
		class BatcherOddEvenMergeSort //Категорія Concurrent_Sort
		{
		public:
			BatcherOddEvenMergeSort(type_array *array, asize_t asize);
			void batcher_odd_even_merge_sort();

		private:
			type_array *Array;
			asize_t array_size;
		};

		class BitonicSorter //Категорія Concurrent_Sort
		{
		public:
			BitonicSorter(type_array *array, asize_t asize);
			void bitonic_sorter();

		private:
			type_array *Array;
			asize_t array_size;
		};

		class BogoSort //Категорія Exchange_Sorts
		{
		public:
			BogoSort(type_array *array, asize_t asize);
			void bogo_sort();

		private:
			type_array *Array;
			asize_t array_size;

			void Shuffle();
		};

		class BubbleSort //Категорія Exchange_Sorts
		{
		public:
			BubbleSort(type_array *array, asize_t asize);
			void bubble_sort();

		private:
			type_array *Array;
			asize_t array_size;
		};

		class CocktailShakerSort //Категорія Exchange_Sorts
		{
		public:
			CocktailShakerSort(type_array *array, asize_t asize);
			void cocktail_shaker_sort();

		private:
			type_array *Array;
			asize_t array_size;
		};

		class CombSort //Категорія Exchange_Sorts
		{
		public:
			CombSort(type_array *array, asize_t asize);
			void comb_sort();

		private:
			type_array *Array;
			asize_t array_size;
		};

		class CycleSort //Категорія Selection_Sorts
		{
		public:
			CycleSort(type_array *array, asize_t asize);
			void cycle_sort();

		private:
			type_array *Array;
			asize_t array_size;
		};

		class GnomeSort //Категорія Exchange_Sorts
		{
		public:
			GnomeSort(type_array *array, asize_t asize);
			void gnome_sort();

		private:
			type_array *Array;
			asize_t array_size;
		};

		class HeapSort //Категорія Selection_Sorts
		{
		public:
			HeapSort(type_array *array, asize_t asize);
			void heap_sort();

		private:
			type_array *Array;
			asize_t array_size;

			void heapify(type_array *Array,
						 const asize_t &count,
						 const asize_t &array_size);
		};

		class InsertSort //Категорія Insertion_Sorts
		{
		public:
			InsertSort(type_array *array, asize_t asize);
			void insert_sort();

		private:
			type_array *Array;
			asize_t array_size;
		};

		class LibrarySort //Категорія Insertion_Sorts
		{
		public:
			LibrarySort(type_array *array, asize_t asize);
			void library_sort();

		private:
			type_array *Array;
			asize_t array_size;

			type_array *gaps, *library[2];
			asize_t lib_size = 0, index_pos = 0, insert, index_pos_for_output = 0;
			bool target_lib = false, *numbered;

			void initialization();
			void binarysearch();
			void insertion();
			void rebalancing();
			void finalization();
		};

		class MergeSort //Категорія Merge_Sorts
		{
		public:
			MergeSort(type_array *array, asize_t asize);
			void merge_sort();

		private:
			type_array *Array;
			asize_t array_size;

			void recursive_merge_sort(const asize_t &left_limit,
									  const asize_t &right_limit);
			void merge(const asize_t &left_limit,
					   const asize_t &middle_limit,
					   const asize_t &right_limit);
		};

		class OddEvenSort //Категорія Exchange_Sorts
		{
		public:
			OddEvenSort(type_array *array, asize_t asize);
			void odd_even_sort();

		private:
			type_array *Array;
			asize_t array_size;
		};

		class PancakeSort //Категорія Other_Sorts
		{
		public:
			PancakeSort(type_array *array, asize_t asize);
			void pancake_sort();

		private:
			type_array *Array;
			asize_t array_size;

			asize_t max_index();
			void flip(asize_t index);
		};

		class PatienceSort //Категорія Insertion_Sorts
		{
		public:
			PatienceSort(type_array *array, asize_t asize);
			void patience_sort();

		private:
			type_array *Array;
			asize_t array_size;

			asize_t *count, pickedRow;
			type_array **decks, *sortedArr, min;

			void initialization();
			void finalization();
		};

		class QuickSort //Категорія Exchange_Sorts
		{
		public:
			QuickSort(type_array *array, asize_t asize);
			void quick_sort();

		private:
			type_array *Array;
			asize_t array_size;

			void recursive_quick_sort(const byte4_t &left_limit,
									  const byte4_t &right_limit);
		};

		class SelectionSort //Категорія Selection_Sorts
		{
		public:
			SelectionSort(type_array *array, asize_t asize);
			void selection_sort();

		private:
			type_array *Array;
			asize_t array_size;
		};

		class ShellSort //Категорія Insertion_Sorts
		{
		public:
			ShellSort(type_array *array, asize_t asize);
			void shell_sort();

		private:
			type_array *Array;
			asize_t array_size;
		};

		class SlowSort //Категорія Exchange_Sorts
		{
		public:
			SlowSort(type_array *array, asize_t asize);
			void slow_sort();

		private:
			type_array *Array;
			asize_t array_size;

			void recursive_slow_sort(const asize_t &left_limit,
									 const asize_t &right_limit);
		};

		class StoogeSort //Категорія Exchange_Sorts
		{
		public:
			StoogeSort(type_array *array, asize_t asize);
			void stooge_sort();

		private:
			type_array *Array;
			asize_t array_size;

			void recursive_stooge_sort(const asize_t &left_limit,
									   const asize_t &right_limit);
		};

		class TimSort //Категорія Hybrid_Sorts
		{
		public:
			TimSort(type_array *array, asize_t asize);
			void tim_sort();

		private:
			type_array *Array;
			asize_t array_size;

			const asize_t RUN = 32;

			void insertionSort(asize_t left_limit, asize_t right_limit);
			void merge(asize_t left_limit, asize_t middle, asize_t right_limit);
		};

		class TreeSort //Категорія Insertion_Sorts
		{
		public:
			TreeSort(type_array *array, asize_t asize);
			void tree_sort();

		private:
			type_array *Array;
			asize_t array_size;

			struct Tree
			{
				type_array data;
				Tree *left, *right;
			};

			Tree *newnode(type_array key);
			Tree *insert(Tree *node, type_array key);
			void store(Tree *root, type_array *Array, asize_t &index);
		};
	};

	class Distribution_Sorts : public ArrayBase<byte8_t>
	{
	public:
		Distribution_Sorts(Array<byte8_t> *&Array);
		void AmericanFlag_Sort();  // №	1	/цілі+ ; вилітає
		void Bead_Sort();		   // №	2	/цілі+ ; обрізає
		void Bucket_Sort();		   // №	3	/цілі+ цілі- цілі+-
		void Counting_Sort();	   // №	4	/цілі+ цілі- цілі+-
		void Flash_Sort();		   // №	5	/цілі+ цілі- цілі+-
		void Interpolation_Sort(); // №	6	/цілі+ цілі- цілі+-
		void Pigeonhole_Sort();	   // №	7	/цілі+ цілі- цілі+-
		void Radix_Sort();		   // №	8	/цілі+ ; не сортує

		class AmericanFlagSort
		{
		public:
			// https://github.com/phishman3579/java-algorithms-implementation/blob/master/src/com/jwetherell/algorithms/sorts/AmericanFlagSort.java
			AmericanFlagSort(byte8_t *array, asize_t asize);
			void american_flag_sort();

		private:
			byte8_t *Array;
			asize_t array_size;

			const byte8_t NUMBER_OF_BUCKETS = 10; // 10 for base 10 numbers

			void recursive_american_flag_sort(byte8_t start,
											  byte8_t length,
											  byte8_t divisor);
			byte8_t getMaxNumberOfDigits();
			byte8_t getDigit(byte8_t integer, byte8_t divisor);
		};

		class BeadSort
		{
		public:
			BeadSort(byte8_t *array, asize_t asize);
			void bead_sort();

		private:
			byte8_t *Array, max;
			asize_t array_size;
			ubit8_t *beads;
		};

		class BucketSort
		{
		public:
			// https://github.com/TheAlgorithms/C-Plus-Plus/blob/master/sorting/bucket_sort.cpp
			BucketSort(byte8_t *array, asize_t asize);
			void bucket_sort();

		private:
			byte8_t *Array, **bucket, min, max, range;
			asize_t array_size, bucket_index, array_index = 0;
		};

		class CountingSort
		{
		public:
			CountingSort(byte8_t *array, asize_t asize);
			void counting_sort();

		private:
			byte8_t *Array, *tempArray, min, max;
			asize_t array_size;
		};

		class FlashSort
		{
		public:
			// https://javascript.algorithmexamples.com/web/Sorts/flashSort.html
			FlashSort(byte8_t *array, asize_t asize);
			void flash_sort();

		private:
			byte8_t *Array, *L, flash;
			asize_t array_size, min = 0, max = 0, move = 0, j = 0, k;
		};

		class InterpolationSort
		{
		public:
			// https://github.com/aniketsatarkar/Sorting-Algorithms-in-C/blob/master/InterpolationSort.h
			InterpolationSort(byte8_t *array, asize_t asize);
			void interpolation_sort();

		private:
			byte8_t *Array;
			asize_t array_size;

			const asize_t MIN_SORTABLE_LENGTH = 128;

			byte8_t ifac, temp;
			byte8_t nArray_min, nArray_max, index_min;
			byte8_t *space, *cmp_index, *cum, *hist, *sorted;
			byte8_t ComplexityCount = 0;

			void getMin();
			void getMax();
		};

		class PigeonholeSort
		{
		public:
			PigeonholeSort(byte8_t *array, asize_t asize);
			void pigeonhole_sort();

		private:
			byte8_t *Array, **hole, min, max;
			asize_t array_size, range, count = 0;
		};

		class RadixSort
		{
		public:
			RadixSort(byte8_t *array, asize_t asize);
			void radix_sort();

		private:
			byte8_t *Array, *tempArray, *bucket, exp = 1, bit = 10, max, current;
			asize_t array_size;
		};
	};

	/* ****+/^^^/+++++-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+++++/^^^/+**** *
	 * #*****+/^^^/+++++-/+/-+-+                         +-+-/+/-+++++/^^^/+*****# *
	 * #*-*%*-*+                                                         +*-*%*-*# *
	 * %%%%%                       $------------------$                      %%%%% *
	 * -->                             ALGOR_MATRIX                            <-- *
	 * %%%%%                       $------------------$                      %%%%% *
	 * #*-*%*-*+                                                         +*-*%*-*# *
	 * #*****+/^^^/+++++-/+/-+-+                         +-+-/+/-+++++/^^^/+*****# *
	 * ****+/^^^/+++++-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+++++/^^^/+**** */

	// class Matrix
	//{
	// public:
	//     Matrix();
	// protected:
	// };

	/* ****+/^^^/+++++-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+++++/^^^/+**** *
	 * #*****+/^^^/+++++-/+/-+-+                         +-+-/+/-+++++/^^^/+*****# *
	 * #*-*%*-*+                                                         +*-*%*-*# *
	 * %%%%%                       $------------------$                      %%%%% *
	 * -->                              ALGOR_HEAP                             <-- *
	 * %%%%%                       $------------------$                      %%%%% *
	 * #*-*%*-*+                                                         +*-*%*-*# *
	 * #*****+/^^^/+++++-/+/-+-+                         +-+-/+/-+++++/^^^/+*****# *
	 * ****+/^^^/+++++-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+++++/^^^/+**** */

	// class Heap
	//{
	// public:
	//     Heap();
	// protected:
	// };

	/* ****+/^^^/+++++-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+++++/^^^/+**** *
	 * #*****+/^^^/+++++-/+/-+-+                         +-+-/+/-+++++/^^^/+*****# *
	 * #*-*%*-*+                                                         +*-*%*-*# *
	 * %%%%%                       $------------------$                      %%%%% *
	 * -->                              ALGOR_LIST                             <-- *
	 * %%%%%                       $------------------$                      %%%%% *
	 * #*-*%*-*+                                                         +*-*%*-*# *
	 * #*****+/^^^/+++++-/+/-+-+                         +-+-/+/-+++++/^^^/+*****# *
	 * ****+/^^^/+++++-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+-+-+-/&/-+++++/^^^/+**** */

	// class List
	//{
	// public:
	//     List();
	// protected:
	// };
} // ALGOR namespace end

#endif // ALGOR_HPP
