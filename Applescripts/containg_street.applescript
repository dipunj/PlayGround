set ctr to 0
set num to 0

-- to remove address containing "123 Street" as street name from all the contacts

tell application "Contacts"
	repeat with i from 1 to (count every person)
		set theAddresses to properties of addresses of person i
		repeat with j from 1 to (count of theAddresses)
			set num to num + 1
			if street of item j of theAddresses contains "saif" then
				set ctr to ctr + 1
				log "found" & ctr & "fake address"
				set street of item j of addresses of person i to ""
				set city of item j of addresses of person i to ""
				set zip of item j of addresses of person i to ""
				set country of item j of addresses of person i to ""
			end if
			log "processed " & num & "total addresses"
		end repeat
		log "processed " & i & "contacts"
	end repeat
	log "DONE"
	save
end tell