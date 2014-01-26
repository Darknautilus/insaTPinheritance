#!/usr/bin/env ruby

require './Tester'

FLAG_OK = "OK"
FLAG_ERR = "ERR"

MESSAGE_MARK = "#"

INVALID_COMMAND = MESSAGE_MARK + "invalid command"
INVALID_PARAMETERS = MESSAGE_MARK + "invalid parameters"
INVALID_PARAM_FORMAT = MESSAGE_MARK + "some arguments aren't in the good format"

EXISTING_FILE = MESSAGE_MARK + "File already exists, overwrite? (y/N)"
WRITING_CANCELLED = MESSAGE_MARK + "writing cancelled by user"
WRITING_ERR = MESSAGE_MARK + "error writing in the file"

LOADING_ERR = MESSAGE_MARK + "error loading the file"
OPENING_ERR = MESSAGE_MARK + "file could't be opened"

MOVE_ERR = MESSAGE_MARK + "error moving the element"
DELETE_ERR = MESSAGE_MARK + "some elements couldn't be deleted"
ADD_POINT_ERR = MESSAGE_MARK + "some points couldn't be added"
ADD_AO_ERR = MESSAGE_MARK + "some elements couldn't be agregated"

prog = ARGV[0]
tester = Tester.new(prog)
tester.test("","ADD.AO.1.in","ADD.AO.1.out")
tester.test("","ADD.AO.2.in",[FLAG_ERR,INVALID_PARAMETERS])
tester.test("","ADD.AO.3.in",[FLAG_ERR,ADD_AO_ERR]+FLAG_OK.repeat(2)+[FLAG_ERR,ADD_AO_ERR])
tester.test("","ADD.Circle.1.in","ADD.Circle.1.out")
tester.test("","ADD.Circle.2.in",[FLAG_ERR,INVALID_PARAMETERS]*2)
tester.test("","ADD.Circle.3.in",[FLAG_ERR,INVALID_PARAM_FORMAT])
tester.test("","ADD.Line.1.in","ADD.Line.1.out")
tester.test("","ADD.Line.2.in",[FLAG_ERR,INVALID_PARAMETERS]*4)
tester.test("","ADD.Line.3.in",[FLAG_ERR,INVALID_PARAM_FORMAT])
tester.test("","ADD.Polyline.1.in","ADD.Polyline.1.out")
tester.test("","ADD.Polyline.2.in",[FLAG_ERR,INVALID_PARAMETERS]*3)
tester.test("","ADD.Polyline.3.in",[FLAG_ERR,INVALID_PARAM_FORMAT])
tester.test("","ADD.Rectangle.1.in","ADD.Rectangle.1.out")
tester.test("","ADD.Rectangle.2.in",[FLAG_ERR,INVALID_PARAMETERS]*4)
tester.test("","ADD.Rectangle.3.in",[FLAG_ERR,INVALID_PARAM_FORMAT])
tester.test("","MOVE.1.in","MOVE.1.out")
tester.test("","MOVE.2.in","MOVE.2.out")
tester.test("","DELETE.1.in",FLAG_OK.repeat(7))
tester.test("","DELETE.2.in","DELETE.2.out")
tester.test("","LOAD.1.in","LOAD.1.out")
tester.test("","LOAD.2.in","LOAD.2.out")
puts tester.to_s
