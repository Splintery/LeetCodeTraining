if [ -e easy/a.out ]; then
	rm easy/a.out
	echo "cleaning easy"
fi
if [ -e medium/a.out ]; then
	rm medium/a.out
	echo "cleaning medium"
fi
if [ -e hard/a.out ]; then
	rm hard/a.out
	echo "cleaing hard"
fi
echo "done cleaning."
