-- initialize the counter to 1
set ctr to 0


-- tells the number of doctors in the address book
tell application "Contacts"
	repeat with i from 1 to (count every person)
		if first name of person i begins with "Dr" or title of person i begins with "Dr" then
			set ctr to ctr + 1
			log "" & name of person i & ""
		end if
	end repeat
	log "Total num of doctors = " & ctr & ""
end tell