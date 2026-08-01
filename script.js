// ==========================================
// 1. 聯絡表單驗證與深色模式邏輯
// ==========================================
document.addEventListener('DOMContentLoaded', () => {
    
    // --- 1. 深色模式切換功能 ---
    const themeToggleBtn = document.getElementById('theme-toggle');
    const htmlElement = document.documentElement;

    // 檢查瀏覽器快取是否有快取過主題偏好，無則預設淺色
    const savedTheme = localStorage.getItem('theme') || 'light';
    htmlElement.setAttribute('data-theme', savedTheme);
    themeToggleBtn.textContent = savedTheme === 'dark' ? '☀️' : '🌙';

    themeToggleBtn.addEventListener('click', () => {
        const currentTheme = htmlElement.getAttribute('data-theme');
        let newTheme = 'light';

        if (currentTheme === 'light') {
            newTheme = 'dark';
            themeToggleBtn.textContent = '☀️';
        } else {
            newTheme = 'light';
            themeToggleBtn.textContent = '🌙';
        }

        htmlElement.setAttribute('data-theme', newTheme);
        localStorage.setItem('theme', newTheme);
    });


    // --- 2. 聯絡表單驗證邏輯 ---
    const form = document.getElementById('contact-form');
    const nameInput = document.getElementById('user-name');
    const emailInput = document.getElementById('user-email');
    const messageInput = document.getElementById('user-message');
    const successBanner = document.getElementById('success-banner');

    // 驗證輔助函式
    const validateField = (input, condition) => {
        const formGroup = input.parentElement;
        if (condition) {
            formGroup.classList.remove('invalid');
            return true;
        } else {
            formGroup.classList.add('invalid');
            return false;
        }
    };

    // 驗證 Email 的正則表達式
    const isValidEmail = (email) => {
        const regex = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
        return regex.test(email);
    };

    // 監聽表單送出
    form.addEventListener('submit', (e) => {
        e.preventDefault(); // 阻止表單跳頁

        // 執行驗證
        const isNameValid = validateField(nameInput, nameInput.value.trim() !== '');
        const isEmailValid = validateField(emailInput, isValidEmail(emailInput.value.trim()));
        const isMessageValid = validateField(messageInput, messageInput.value.trim() !== '');

        // 驗證成功處理
        if (isNameValid && isEmailValid && isMessageValid) {
            successBanner.style.display = 'block';
            form.reset(); // 清空表單

            // 3秒後自動關閉成功提示
            setTimeout(() => {
                successBanner.style.display = 'none';
            }, 3000);
        }
    });

    // 使用者一輸入，立刻解除錯誤紅框外觀
    const inputs = [nameInput, emailInput, messageInput];
    inputs.forEach(input => {
        input.addEventListener('input', () => {
            input.parentElement.classList.remove('invalid');
        });
    });
});
