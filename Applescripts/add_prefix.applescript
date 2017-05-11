set ctr to 0
set num to 0

-- adds "Dr." as prefix to all persons whose first name begins with "Dr"
tell application "Contacts"
	repeat with i from 1 to (count every person)
		set num to num + 1
		
		-- to add prefix to Dr. if Dr is found
		if first name of person i begins with "Dr" then
			set ctr to ctr + 1
			log "Dr.s found = " & ctr & ""
			set title of person i to "Dr."
		end if
		log "processed " & num & "total doctors"
	end repeat
	log "" & i & "contacts"
	save
end tell
log "DONE"