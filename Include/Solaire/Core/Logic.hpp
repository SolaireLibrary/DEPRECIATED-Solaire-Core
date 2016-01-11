#ifndef SOLAIRE_LOGIC_HPP
#define SOLAIRE_LOGIC_HPP

//Copyright 2015 Adam Smith
//
//Licensed under the Apache License, Version 2.0 (the "License");
//you may not use this file except in compliance with the License.
//You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
//Unless required by applicable law or agreed to in writing, software
//distributed under the License is distributed on an "AS IS" BASIS,
//WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//See the License for the specific language governing permissions and
//limitations under the License.

// Contact :
// Email             : solairelibrary@mail.com
// GitHub repository : https://github.com/SolaireLibrary/SolaireCPP

/*!
	\file Logic.hpp
	\brief
	\author
	Created			: Adam Smith
	Last modified	: Adam Smith
	\version 1.0
	\date
	Created			: 9th January 2016
	Last Modified	: 9th January 2016
*/

namespace Solaire {

    /*!
        \brief Perform a logical OR operation on two boolean values.
        \detail The truth table for this operation is:
        <table>
            <tr>
                <th>Input A</th>
                <th>Input B</th>
                <th>Output</th>
            <tr>
            <tr>
                <td>0</td>
                <td>0</td>
                <td>0</td>
            <tr>
            <tr>
                <td>1</td>
                <td>0</td>
                <td>1</td>
            <tr>
            <tr>
                <td>0</td>
                <td>1</td>
                <td>1</td>
            <tr>
            <tr>
                <td>1</td>
                <td>1</td>
                <td>1</td>
            <tr>
        </table>
        \param aFirst The left hand value.
        \param aSecond The right hand value.
        \return The result of the operation.
    */
    static constexpr bool logicalOr(const bool aFirst, const bool aSecond) {
        return aFirst || aSecond;
    }

    /*!
        \brief Perform a logical AND operation on two boolean values.
        \detail The truth table for this operation is:
        <table>
            <tr>
                <th>Input A</th>
                <th>Input B</th>
                <th>Output</th>
            <tr>
            <tr>
                <td>0</td>
                <td>0</td>
                <td>0</td>
            <tr>
            <tr>
                <td>1</td>
                <td>0</td>
                <td>0</td>
            <tr>
            <tr>
                <td>0</td>
                <td>1</td>
                <td>0</td>
            <tr>
            <tr>
                <td>1</td>
                <td>1</td>
                <td>1</td>
            <tr>
        </table>
        \param aFirst The left hand value.
        \param aSecond The right hand value.
        \return The result of the operation.
    */
    static constexpr bool logicalAnd(const bool aFirst, const bool aSecond) {
        return aFirst && aSecond;
    }

    /*!
        \brief Perform a logical XOR operation on two boolean values.
        \detail The truth table for this operation is:
        <table>
            <tr>
                <th>Input A</th>
                <th>Input B</th>
                <th>Output</th>
            <tr>
            <tr>
                <td>0</td>
                <td>0</td>
                <td>0</td>
            <tr>
            <tr>
                <td>1</td>
                <td>0</td>
                <td>1</td>
            <tr>
            <tr>
                <td>0</td>
                <td>1</td>
                <td>1</td>
            <tr>
            <tr>
                <td>1</td>
                <td>1</td>
                <td>0</td>
            <tr>
        </table>
        \param aFirst The left hand value.
        \param aSecond The right hand value.
        \return The result of the operation.
    */
    static constexpr bool logicalXor(const bool aFirst, const bool aSecond) {
        return (aFirst || aSecond) && ! (aFirst && aSecond);
    }

    /*!
        \brief Perform a logical NOR operation on two boolean values.
        \detail The truth table for this operation is:
        <table>
            <tr>
                <th>Input A</th>
                <th>Input B</th>
                <th>Output</th>
            <tr>
            <tr>
                <td>0</td>
                <td>0</td>
                <td>1</td>
            <tr>
            <tr>
                <td>1</td>
                <td>0</td>
                <td>0</td>
            <tr>
            <tr>
                <td>0</td>
                <td>1</td>
                <td>0</td>
            <tr>
            <tr>
                <td>1</td>
                <td>1</td>
                <td>0</td>
            <tr>
        </table>
        \param aFirst The left hand value.
        \param aSecond The right hand value.
        \return The result of the operation.
    */
    static constexpr bool logicalNor(const bool aFirst, const bool aSecond) {
        return ! (aFirst || aSecond);
    }

    /*!
        \brief Perform a logical NAND operation on two boolean values.
        \detail The truth table for this operation is:
        <table>
            <tr>
                <th>Input A</th>
                <th>Input B</th>
                <th>Output</th>
            <tr>
            <tr>
                <td>0</td>
                <td>0</td>
                <td>1</td>
            <tr>
            <tr>
                <td>1</td>
                <td>0</td>
                <td>1</td>
            <tr>
            <tr>
                <td>0</td>
                <td>1</td>
                <td>1</td>
            <tr>
            <tr>
                <td>1</td>
                <td>1</td>
                <td>0</td>
            <tr>
        </table>
        \param aFirst The left hand value.
        \param aSecond The right hand value.
        \return The result of the operation.
    */
    static constexpr bool logicalNand(const bool aFirst, const bool aSecond) {
        return ! (aFirst && aSecond);
    }

    /*!
        \brief Perform a logical XNOR operation on two boolean values.
        \detail The truth table for this operation is:
        <table>
            <tr>
                <th>Input A</th>
                <th>Input B</th>
                <th>Output</th>
            <tr>
            <tr>
                <td>0</td>
                <td>0</td>
                <td>1</td>
            <tr>
            <tr>
                <td>1</td>
                <td>0</td>
                <td>0</td>
            <tr>
            <tr>
                <td>0</td>
                <td>1</td>
                <td>0</td>
            <tr>
            <tr>
                <td>1</td>
                <td>1</td>
                <td>1</td>
            <tr>
        </table>
        \param aFirst The left hand value.
        \param aSecond The right hand value.
        \return The result of the operation.
    */
    static constexpr bool logicalXnor(const bool aFirst, const bool aSecond) {
        return (aFirst && aSecond) || ! (aFirst || aSecond);
    }
}


#endif
