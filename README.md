# 📅 Double Linked List Takvim Uygulaması

Bu projede C++ ile Çift Yönli Bağlı Lİste (DOuble Linked Lİst) yapısını kullanarak yapılmış terminal tabanlı bir takvim uygulmasıdır.
Kullanıcı çeşitli seçenekler arasından seçim yaparak takvime gün ekleyebilir,silebilir, içinde gezebilir .

## 🚀 Özellikler

- 30 günlük takvim otomatik oluşturulur.  
- Her güne:
 - Başlık (Title)
 - İçerik (Content)
- Öncelik (Priority) bilgileri eklenebilir.
- Günler arasında çift yönlü geçiş yapılabilir (`p` ve `n` tuşlarıyla).
- Boş günlere yeni etkinlik eklenebilir.
- Dolu günlerde etkinlik bilgisi görüntülenebilir.
- Etkinlikler silinebilir veya değiştirilebilir.

---

## 🧠 Çalışma Mantığı:
-Projede her gün Node isminde bir struct olarak tanımlanmıştır. Her Node içinde verileri ve önceki ile sonraki günün işaretçisini taşır.
-Takvim döngüsel (Circular) bir biçimdedir 30. günden sonra 1.güne geri gelir.


## 🧩 Sınıf Yapısı

- **Day**  
  Her günü temsil eder (gün numarası, başlık, içerik, öncelik ve bağlantılar).

- **Calendar**  
  Tüm takvimi yönetir:
  - `initCalendar()` → Takvimi başlatır  
  - `addEvent()` → Yeni etkinlik ekler  
  - `changeEvent()` → Var olan etkinliği değiştirir  
  - `deleteEvent()` → Etkinliği siler  
  - `listEvents()` → Günler arasında gezinmeyi sağlar  

---

## 💻 Çalıştırma

1. Programı derle:
   ```bash
   g++ calendar.cpp -o calendar
2. Çalıştır:
```bash
   ./calendar ```


