#pragma once
/*
	Copyright (C) 2022  Barth.Feudong
	Author can be contacted here: <https://github.com/mrSchaffman/Cpp-Calculator>

	This file is part of the Calculator project.
	using the COM, the win32 API for the GUI,
	the MVC Architecture.

	Calculator is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	Calculator is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <https://www.gnu.org/licenses/>.

*/

#ifndef TOKENIZER_H
#define TOKENIZER_H
#include<string>
#include<vector>

namespace utility
{
	using Token = std::string;
	using Tokens = std::vector<Token>;
	using const_iterator = Tokens::const_iterator;

	class Tokenizer
	{
	public:
		explicit Tokenizer(const std::string&);
		explicit Tokenizer(std::istream&);
		~Tokenizer();
		size_t count() { return m_tokens.size(); }

		// util for range for loop
		const_iterator begin() { return m_tokens.begin(); }
		const_iterator end() { return m_tokens.end(); }

		// random access iterator.
		const Token& operator[](size_t i)const { return m_tokens[i]; }

	private:
		Tokenizer() = delete;
		Tokenizer(const Tokenizer&) = delete;
		Tokenizer(Tokenizer&&) = delete;
		Tokenizer& operator=(const Tokenizer&) = delete;
		Tokenizer& operator=(Tokenizer&&) = delete;

		void tokenize(std::istream&);
		Tokens m_tokens;
	};
}
#endif // !TOKENIZER_H


