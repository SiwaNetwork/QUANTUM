result=$(lspci | grep Meta | wc -l)
echo "Тест обнаружения временной карты начат"
if [ "$result" -eq "1" ];
then
	echo "Тест обнаружения временной карты: Пройден!"
else
	result=$(lspci)
	echo $result
	echo "Тест обнаружения временной карты: ПРОВАЛ!!!"
	exit
fi

result=$(modprobe ptp_ocp)
result=$(dmesg | grep ptp_ocp | wc -l)
echo "Тест загрузки модуля временной карты начат"
if [ "$result" -ge "7" ];
then
	echo "Тест загрузки модуля временной карты: Пройден!"
else
	result=$(dmesg | grep ptp_ocp)
	echo $result
	echo "Тест загрузки модуля временной карты: ПРОВАЛ!!"
	exit
fi

gnss_tty=$(dmesg | grep ptp_ocp | grep GNSS: | cut -d" " -f 10)
gnss_tty_count=$(echo $gnss_tty | wc -l)

echo "Тестирование серийного порта GNSS начато"
if [ "$gnss_tty_count" -eq "1" ];
then
	echo "Тестирование серийного порта GNSS: Пройдено!"
else
	result=$(dmesg | grep ptp_ocp)
	echo $result
	echo "Тестирование серийного порта GNSS: ПРОВАЛ!!!"
	exit
fi


ubx_log=$(ubxtool -f $gnss_tty -s 115200 -p MON-VER | grep extension | wc -l)

echo "Тестирование GNSS TimeLS начато"
if [ "$ubx_log" -ge "2" ];
then
	echo "Тестирование GNSS TimeLS: Пройдено!"
else
	result=$(ubxtool -f $gnss_tty -s 115200 -p MON-VER)
	echo $result
	echo "Тестирование GNSS TimeLS: ПРОВАЛ!!!"
	exit
fi



echo "Тестирование временной карты завершено успешно!"
