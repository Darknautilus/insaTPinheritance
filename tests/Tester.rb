#!/usr/bin/env ruby

## =====
## INSA Lyon, Département Informatique
## TP C++ 3IF :  Héritage et polymorphisme
## Auteur : B3229
## =====

class String
	def repeat(times)
		out = []
		times.times do
			out.push(self)
		end
		return out
	end
end

class Tester
	def initialize(programPath)
		@program = programPath
		@results = []
		@passed = 0
	end

	def test(name,input,expected_output)
		if name.empty?
			if File.exist?(input)
				name = input
			else
				name = "Unnamed test"
			end
		end
		if input.kind_of?(Array)
			input = input.join("\n")
		elsif File.exist?(input)
			input = File.open(input).read
		end
		output = ""
		IO.popen(@program,'r+') do |pipe|
			pipe.puts(input)
			pipe.close_write
			output = pipe.read
		end
		output.strip!
		if expected_output.kind_of?(Array)
			expected_output = expected_output.join("\n")
			expected_output += "\n"
		elsif File.exist?(expected_output)
			expected_output = File.open(expected_output).read
		else
			expected_output += "\n"
		end
		expected_output.strip!
		result = [name,(output == expected_output),input,output,expected_output]
		@results.push(result)
		if result[1]
			@passed += 1
		end
		return result[1]
	end

	def to_s
		puts "=========================="
		puts "= Test of #{@program}"
		puts "=========================="
		@results.each do |result|
			if result[1]
				passed = "PASSED"
			else
				passed = "FAILED\nExpected:\n" + result[4] + "\nResult:\n" + result[3]
			end
			puts result[0] + " ==> " + passed
			puts "=========================="
		end
		puts "Total: " + @results.length.to_s + " tests, #{@passed} passed"
	end
end
