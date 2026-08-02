<!DOCTYPE html>
<html lang="zh-TW" data-theme="light">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>個人自我介紹網站</title>
    <!-- 引入 Cropper.js 樣式 (用於圖片裁剪選取範圍) -->
    <link rel="stylesheet" href="https://cloudflare.com">
    
    <!-- ==========================================
       內嵌網頁樣式 (style.css 內容)
       ========================================== -->
    <style>
        /* 1. 全域變數與重設 */
        :root {
            --bg-color: #ffffff;
            --text-color: #333333;
            --primary-color: #4f46e5;
            --nav-bg: rgba(255, 255, 255, 0.8);
            --transition-speed: 0.3s;
        }

        [data-theme="dark"] {
            --bg-color: #0f172a;
            --text-color: #f8fafc;
            --primary-color: #818cf8;
            --nav-bg: rgba(15, 23, 42, 0.8);
        }

        * {
            margin: 0;
            padding: 0;
            box-sizing: border-box;
        }

        html {
            scroll-behavior: smooth;
            font-family: -apple-system, BlinkMacSystemFont, "Segoe UI", Roboto, Helvetica, Arial, sans-serif;
        }

        body {
            background-color: var(--bg-color);
            color: var(--text-color);
            transition: background-color var(--transition-speed), color var(--transition-speed);
            line-height: 1.6;
        }

        /* 2. 導覽列樣式 (Navbar) */
        .navbar {
            position: fixed;
            top: 0;
            left: 0;
            width: 100%;
            height: 70px;
            display: flex;
            justify-content: space-between;
            align-items: center;
            padding: 0 10%;
            background-color: var(--nav-bg);
            backdrop-filter: blur(10px);
            z-index: 1000;
            border-bottom: 1px solid rgba(0, 0, 0, 0.05);
        }

        [data-theme="dark"] .navbar {
            border-bottom-color: rgba(255, 255, 255, 0.05);
        }

        .logo {
            font-size: 1.5rem;
            font-weight: 700;
            color: var(--primary-color);
        }

        .nav-links a {
            color: var(--text-color);
            text-decoration: none;
            margin-left: 2rem;
            font-weight: 500;
            transition: color var(--transition-speed);
        }

        .nav-links a:hover {
            color: var(--primary-color);
        }

        .theme-btn {
            background: none;
            border: none;
            font-size: 1.2rem;
            cursor: pointer;
            padding: 5px;
            border-radius: 50%;
            transition: transform var(--transition-speed);
        }

        .theme-btn:hover {
            transform: scale(1.1);
        }

        /* 3. 首頁樣式 (Hero Section) */
        .hero-section {
            height: 100vh;
            display: flex;
            justify-content: center;
            align-items: center;
            text-align: center;
            padding: 0 20px;
            padding-top: 70px;
        }

        .hero-container {
            opacity: 0;
            transform: translateY(20px);
            animation: fadeInUp 1s ease forwards;
        }

        .hero-title {
            font-size: 4rem;
            font-weight: 800;
            letter-spacing: 2px;
        }

        /* 4. 作品區樣式 (Projects Section) */
        .projects-section {
            padding: 100px 10%;
            background-color: rgba(0, 0, 0, 0.02);
        }

        [data-theme="dark"] .projects-section {
            background-color: rgba(255, 255, 255, 0.02);
        }

        .section-title {
            text-align: center;
            font-size: 2rem;
            margin-bottom: 3rem;
            position: relative;
        }

        .section-title::after {
            content: '';
            position: absolute;
            bottom: -10px;
            left: 50%;
            transform: translateX(-50%);
            width: 50px;
            height: 4px;
            background-color: var(--primary-color);
            border-radius: 2px;
        }

        .projects-grid {
            display: grid;
            grid-template-columns: repeat(3, 1fr);
            gap: 2rem;
        }

        .project-card {
            background-color: var(--bg-color);
            border-radius: 12px;
            overflow: hidden;
            box-shadow: 0 4px 6px -1px rgba(0, 0, 0, 0.1), 0 2px 4px -1px rgba(0, 0, 0, 0.06);
            transition: transform var(--transition-speed) ease, box-shadow var(--transition-speed) ease;
        }

        .project-card:hover {
            transform: translateY(-8px);
            box-shadow: 0 20px 25px -5px rgba(0, 0, 0, 0.1), 0 10px 10px -5px rgba(0, 0, 0, 0.04);
        }

        .card-img-box {
            width: 100%;
            height: 200px;
            overflow: hidden;
        }

        .card-img {
            width: 100%;
            height: 100%;
            object-fit: cover;
            transition: transform var(--transition-speed) ease;
        }

        .project-card:hover .card-img {
            transform: scale(1.05);
        }

        .card-content {
            padding: 1.5rem;
        }

        .card-title {
            font-size: 1.25rem;
            margin-bottom: 0.5rem;
            color: var(--text-color);
        }

        .card-text {
            font-size: 0.95rem;
            color: #64748b;
        }

        [data-theme="dark"] .card-text {
            color: #94a3b8;
        }

        /* 5. 聯絡區與大頭貼上傳樣式 */
        .contact-section {
            padding: 100px 10%;
        }

        .contact-container {
            max-width: 600px;
            margin: 0 auto;
        }

        .contact-form {
            background-color: var(--bg-color);
            padding: 2.5rem;
            border-radius: 16px;
            box-shadow: 0 10px 30px rgba(0, 0, 0, 0.05);
            border: 1px solid rgba(0, 0, 0, 0.03);
        }

        [data-theme="dark"] .contact-form {
            border-color: rgba(255, 255, 255, 0.05);
            box-shadow: 0 10px 30px rgba(0, 0, 0, 0.2);
        }

        .avatar-upload-wrapper {
            display: flex;
            flex-direction: column;
            align-items: center;
            margin-bottom: 2rem;
        }

        .avatar-preview-box {
            width: 120px;
            height: 120px;
            border-radius: 50%; 
            overflow: hidden;   
            border: 3px solid var(--primary-color);
            box-shadow: 0 4px 12px rgba(0, 0, 0, 0.1);
            background-color: #f1f5f9;
            margin-bottom: 1rem;
        }

        .avatar-preview-img {
            width: 100%;
            height: 100%;
            object-fit: cover;
        }

        .avatar-upload-btn {
            padding: 0.5rem 1rem;
            font-size: 0.85rem;
            font-weight: 600;
            color: var(--primary-color);
            border: 1px solid var(--primary-color);
            border-radius: 20px;
            cursor: pointer;
            transition: all var(--transition-speed);
        }

        .avatar-upload-btn:hover {
            background-color: var(--primary-color);
            color: white;
        }

        .form-group {
            margin-bottom: 1.5rem;
            position: relative;
        }

        .form-group label {
            display: block;
            font-size: 0.9rem;
            font-weight: 600;
            margin-bottom: 0.5rem;
            color: var(--text-color);
        }

        .form-group input,
        .form-group textarea {
            width: 100%;
            padding: 0.75rem 1rem;
            font-size: 1rem;
            background-color: var(--bg-color);
            color: var(--text-color);
            border: 1px solid #cbd5e1;
            border-radius: 8px;
            outline: none;
            transition: border-color var(--transition-speed), box-shadow var(--transition-speed);
        }

        [data-theme="dark"] .form-group input,
        [data-theme="dark"] .form-group textarea {
            border-color: #334155;
        }

        .form-group input:focus,
        .form-group textarea:focus {
            border-color: var(--primary-color);
            box-shadow: 0 0 0 3px rgba(79, 70, 229, 0.15);
        }

        .form-group.invalid input,
        .form-group.invalid textarea {
            border-color: #ef4444;
        }

        .form-group.invalid input:focus,
        .form-group.invalid textarea:focus {
            box-shadow: 0 0 0 3px rgba(239, 68, 68, 0.15);
        }

        .error-msg {
            display: none;
            color: #ef4444;
            font-size: 0.8rem;
            margin-top: 0.25rem;
        }

        .form-group.invalid .error-msg {
            display: block;
        }

        .submit-btn {
            width: 100%;
            padding: 0.85rem;
            background-color: var(--primary-color);
            color: white;
            border: none;
            border-radius: 8px;
            font-size: 1rem;
            font-weight: 600;
            cursor: pointer;
            transition: background-color var(--transition-speed), transform var(--transition-speed);
        }

        .submit-btn:hover {
            background-color: #4338ca;
            transform: translateY(-1px);
        }

        .submit-btn:active {
            transform: translateY(1px);
        }

        .success-banner {
            display: none;
            margin-top: 1.5rem;
            padding: 1rem;
            background-color: #bbf7d0;
            color: #166534;
            border-radius: 8px;
            text-align: center;
            font-size: 0.95rem;
            font-weight: 500;
        }

        [data-theme="dark"] .success-banner {
            background-color: #14532d;
            color: #bbf7d0;
        }

        /* 6. 圖片裁剪彈出式視窗 (Crop Modal) */
        .crop-modal {
