set ctr to 0
set num to 0

tell application "Contacts"
	repeat with i from 1 to (count every person)
		set num to num + 1
		-- to add prefix to Dr. if Dr is found
		if first name of person i begins with "Dr" then
			set ctr to ctr + 1
			log "found = " & name of person i & " " & ctr & ""
			set title of person i to "Dr."
		end if
	end repeat
	log "processed " & ctr & " doctors"
	save
end tell

set ctr to 0
set num to 0

tell application "Contacts"
	repeat with i from 1 to (count every person)
		set num to num + 1
		if first name of person i begins with "Dr. " then
			set ctr to ctr + 1
			log "" & ctr & "Dr.s found = " & first name of person i & ""
			set first name of person i to my trim_line(first name of person i, "Dr. ", 0)
			log "" & first name of person i & ""
		end if
		if first name of person i begins with "Dr  " then
			set ctr to ctr + 1
			log "" & ctr & "Dr.s found = " & first name of person i & ""
			set first name of person i to my trim_line(first name of person i, "Dr  ", 0)
			log "" & first name of person i & ""
		end if
		if first name of person i begins with "Dr." then
			set ctr to ctr + 1
			log "" & ctr & "Dr.s found = " & first name of person i & ""
			set first name of person i to my trim_line(first name of person i, "Dr.", 0)
			log "" & first name of person i & ""
		end if
		if first name of person i begins with "Dr " then
			set ctr to ctr + 1
			log "" & ctr & "Dr.s found = " & first name of person i & ""
			set first name of person i to my trim_line(first name of person i, "Dr ", 0)
			log "" & first name of person i & ""
		end if
		if first name of person i begins with "Dr" then
			set ctr to ctr + 1
			log "" & ctr & "Dr.s found = " & first name of person i & ""
			set first name of person i to my trim_line(first name of person i, "Dr", 0)
			log "" & first name of person i & ""
		end if
		if first name of person i begins with "." then
			set ctr to ctr + 1
			log "" & ctr & "Dr.s found = " & first name of person i & ""
			set first name of person i to my trim_line(first name of person i, ".", 0)
			log "" & first name of person i & ""
		end if
		
		
		log "processed " & num & "total contacts"
	end repeat
	log "processed " & ctr & " doctors"
	save
end tell
log "DONE"



on trim_line(this_text, trim_chars, trim_indicator)
	-- 0 = beginning, 1 = end, 2 = both
	set x to the length of the trim_chars
	-- TRIM BEGINNING
	if the trim_indicator is in {0, 2} then
		repeat while this_text begins with the trim_chars
			try
				set this_text to characters (x + 1) thru -1 of this_text as string
			on error
				-- the text contains nothing but the trim characters
				return ""
			end try
		end repeat
	end if
	-- TRIM ENDING
	if the trim_indicator is in {1, 2} then
		repeat while this_text ends with the trim_chars
			try
				set this_text to characters 1 thru -(x + 1) of this_text as string
			on error
				-- the text contains nothing but the trim characters
				return ""
			end try
		end repeat
	end if
	return this_text
end trim_line