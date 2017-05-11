set ctr to 0
set num to 0

-- to delete all the addresses of each person
tell application "Contacts"
	repeat with i from 1 to (count every person)
		delete addresses of person i
		log "processed " & i & " contacts"
	end repeat
	log "DONE"
	save
end tell