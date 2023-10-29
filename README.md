บทคัดย่อ
  เนื่องจากในปัจจุบันโรงรถของคนส่วนใหญ่ทั่วไปตามบ้านมักจะเป็นโรงรถแบบต้องใช้คนในการเปิด-ปิดประตูซึ่งอาจจะใช้เวลานาน กลุ่มของเราจึงคิดพัฒนาโครงงาน Amazing Garage ขึ้นมาเพื่อพัฒนาโรงจอดรถให้ทันสมัยมากขึ้น
โดยใช้ Ultrasonic Sensor ในการตรวจับรถว่ากำลังเข้ามาจอดหรือยังถ้าตรวจจับพบประตูของโรงรถจะเปิด-ปิดอัตโนมัติ และเชื่อมกับไฟในโรงรถถ้ามีรถเข้ามาจอดไฟในโรงรถจะติดอัตโนมัติ
และเมื่อจอดรถเสร็จสิ้น ir sensor จะทำการตรวจจับรถในโรงรถว่าเข้ามาจอดและขับออกจากโรงรถแล้วจึงส่งข้อความแจ้งเตือนผ่าน Line ในกลุ่มของครอบครัว
ถ้ารถเข้ามาจอดระบบจะแจ้งเตือนว่า Your car has back แล้วถ้าหากขับรถออกไปจะแจ้งเตือนว่า Your car has left
หากต้องการขับรถออกจากโรงรถหรือว่าคนขับต้องการออกจากโรงรถจะต้องปรบมือหรือดีดนิ้ว 1 ครั้ง เพื่อให้ประตูของโรงรถเปิดและไฟในโรงรถปิดโดยทำงานโดยการใช้ sound sensor
การเปิดประตูโรงรถ จะทำงานโดยใช้ Ultarsonic sensor เชื่อมกับ servo motor

คลิป demo การใช้งาน
https://youtu.be/wHMELFvaDf8?si=E40I22sX4xgu-S-t

อุปกรณ์หลัก
- ultrasonic sensor
- sound sensor
- servo motor
- esp32
- ir sensor

หลักการทำงาน
1. ultrasonic sensor ตรวจจับรถกำลังเข้ามาจอด
2. ตรวจจับพบประตูโรงรถและไฟจะเปิดขึ้นอัตโนมัติ
3. รถเข้าไปจอดในโรงรถสำเร็จ
4. ประตูโรงรถปิดอัตโนมัติ
6. ir sensor ตรวจจับรถในโรงรถ
7. ตรวจจับพบจะทำการแจ้งเตือนผ่าน line ว่า Your car has back
8. คนขับรถต้องการออกจากโรงรถหรือขับรถออกจากโรงรถ
9. ปรบมือหรือดีดนี้ว 1 ครั้ง
10. ประตูโรงรถเปิดและไฟปิดอัตโนมัติ
11. เมื่อขับรถออกจากโรงรถ
12. ir sensor ตรวจจับว่ารถถูกขับออกไป
13. ส่งแจ้งเตือนผ่าน line ว่า Your car has left
14. ขับรถออกสำเร็จ
15. ประตูโรงรถปิดอัตโนมัติ

สมาชิกกลุ่ม
1. นาย ศิรพัชร รัตนพาไชย 65070214
2. นางสาว ศิโรรัตน์ นามบุญ 65070217
3. นาย ศุภชัย มณีรัตน์ 65070224
4. นายสุทธิเกียรติ หัทยาสมบูรณ์ 65070240
