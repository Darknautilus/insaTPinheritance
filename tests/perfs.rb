#!/usr/bin/env ruby

class Benchmark
	def initialize(program, name)
		@name = name
		@program = program
		@nbOps = 0
		@time = 0
	end

	def run(commands,times,nbOps)
		if commands.kind_of?(Array)
			commands = commands.join("\n")
		elsif File.exist?(commands)
			commands = File.open(commands).read
		end
		times.times do
			start = Time.now
			IO.popen(@program,"r+") do |pipe|
				pipe.puts(commands)
				pipe.close_write
			end
			@time += (Time.now - start)
			@nbOps += nbOps
		end
	end
	
	def to_s
		if @nbOps == 0
			nbops = 1
		else
			nbops = @nbOps
		end
		puts "#{@name}: #{@nbOps} done in #{@time} seconds (#{@time/nbops}s per operation)"
		puts "=========================="
	end
end

program = "../bin/B3229"

add = Benchmark.new(program,"ADD")
add.run("ADDtenThousand.in",50,10000)
add.to_s

load = Benchmark.new(program,"LOAD")
load.run("LOADtenThousand.in",50,10000)
load.to_s
