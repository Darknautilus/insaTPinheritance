#!/usr/bin/env ruby

FLAG_OK = "OK"
FLAG_ERR = "ERR"

MESSAGE_MARK = "#"

INVALID_COMMAND = MESSAGE_MARK + "invalid command"
INVALID_PARAMETERS = MESSAGE_MARK + "invalid parameters"
INVALID_PARAM_FORMAT = MESSAGE_MARK + "some arguments aren't in good format"

EXISTING_FILE = MESSAGE_MARK + "File already exists, overwrite? (y/N)"
WRITING_CANCELLED = MESSAGE_MARK + "writing cancelled by user"
WRITING_ERR = MESSAGE_MARK + "error writing in the file"

LOADING_ERR = MESSAGE_MARK + "error loading the file"
OPENING_ERR = MESSAGE_MARK + "file could't be opened"

MOVE_ERR = MESSAGE_MARK + "error moving the element"
DELETE_ERR = MESSAGE_MARK + "some elements couldn't be deleted"
ADD_POINT_ERR = MESSAGE_MARK + "some points couldn't be added"
ADD_AO_ERR = MESSAGE_MARK + "some elements couldn't be agregated"

class Tester
	def initialize(programPath)
		@program = programPath
		@results = []
		@passed = 0
	end

	def test(name,input,expected_output)
		output = ""
		if input.kind_of?(Array)
			input = input.join("\n")
		elsif File.exists?(input)
			input = File.open(input).read
		end
		input += "\nexit"
		IO.popen(@program,'r+') do |pipe|
			pipe.puts(input)
			pipe.close_write
			output = pipe.read
		end
		if expected_output.kind_of?(Array)
			expected_output = expected_output.join("\n")
		elsif File.exists?(expected_output)
			expected_output = File.open(expected_output).read
		end
		expected_output += "\n"
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
				passed = "FAILED\nExpected\n" + result[4] + "\nGiven:\n" + result[3]
			end
			puts result[0] + " ==> " + passed
			puts "=========================="
		end
		puts "Total: " + @results.length.to_s + " tests, #{@passed} passed"
	end
end

class String
	def to_a(times)
		out = []
		times.times do
			out.push(self)
		end
		return out
	end
end

prog = "../bin/B3229"
tester = Tester.new(prog)
tester.test("ADD.AO.1","ADD.AO.1.in",FLAG_OK.to_a(3))
puts tester.to_s
