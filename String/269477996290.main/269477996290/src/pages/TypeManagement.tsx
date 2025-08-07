import { useState } from 'react';
import { Link } from 'react-router-dom';
import { Navbar } from '@/components/Navbar';
import { ResourceTypeCard } from '@/components/ResourceTypeCard';
import { useResourceContext } from '@/contexts/resourceContext.tsx';
import { toast } from 'sonner';

interface NewTypeFormData {
  name: string;
  description: string;
  iconUrl?: string;
}

export default function TypeManagement() {
  const { resourceTypes, addResourceType, deleteResourceType } = useResourceContext();
  const [showForm, setShowForm] = useState(false);
  const [formData, setFormData] = useState<NewTypeFormData>({
    name: '',
    description: '',
    iconUrl: undefined,
  });
  const [previewUrl, setPreviewUrl] = useState<string | null>(null);
  const [isSubmitting, setIsSubmitting] = useState(false);
  
  const handleChange = (e: React.ChangeEvent<HTMLInputElement | HTMLTextAreaElement>) => {
    const { name, value } = e.target;
    setFormData(prev => ({ ...prev, [name]: value }));
  };
  
  const handleFileChange = (e: React.ChangeEvent<HTMLInputElement>) => {
    const file = e.target.files?.[0];
    if (!file) return;
    
    // 检查文件类型
    if (!file.type.startsWith('image/')) {
      toast.error('请上传图片文件');
      return;
    }
    
    // 检查文件大小 (限制5MB)
    if (file.size > 5 * 1024 * 1024) {
      toast.error('图片大小不能超过5MB');
      return;
    }
    
    // 读取文件并显示预览
    const reader = new FileReader();
    reader.onload = (event) => {
      const base64Url = event.target?.result as string;
      setPreviewUrl(base64Url);
      setFormData(prev => ({ ...prev, iconUrl: base64Url }));
    };
    reader.readAsDataURL(file);
  };
  
  const handleSubmit = (e: React.FormEvent) => {
    e.preventDefault();
    
    // 表单验证
    if (!formData.name.trim()) {
      toast.error('请输入分类名称');
      return;
    }
    
    setIsSubmitting(true);
    
    try {
      // 添加新分类
      addResourceType({
        name: formData.name.trim(),
        description: formData.description.trim() || undefined,
        iconUrl: formData.iconUrl,
      });
      
      toast.success('分类添加成功');
      
      // 重置表单
      setFormData({ name: '', description: '', iconUrl: undefined });
      setPreviewUrl(null);
      setShowForm(false);
    } catch (error) {
      toast.error('添加分类失败，请重试');
      console.error(error);
    } finally {
      setIsSubmitting(false);
    }
  };
  
  return (
    <div className="min-h-screen bg-gray-50 dark:bg-gray-900">
      <Navbar />
      
      <main className="max-w-7xl mx-auto py-6 px-4 sm:px-6 lg:px-8">
        <div className="flex flex-wrap items-center justify-between gap-4 mb-8">
          <div>
            <h1 className="text-2xl font-bold text-gray-900 dark:text-white">资源分类管理</h1>
            <p className="mt-1 text-gray-600 dark:text-gray-400">
              管理、添加或删除资源分类
            </p>
          </div>
          
          <button
            onClick={() => setShowForm(!showForm)}
            className="inline-flex items-center px-4 py-2 border border-transparent rounded-md shadow-sm text-sm font-medium text-white bg-blue-600 hover:bg-blue-700"
          >
            <i class="fa-solid fa-plus mr-2"></i> {showForm ? '取消' : '添加新分类'}
          </button>
        </div>
        
        {showForm && (
          <div className="bg-white dark:bg-gray-800 rounded-lg shadow overflow-hidden border border-gray-200 dark:border-gray-700 mb-8 p-6">
            <h2 className="text-lg font-medium text-gray-900 dark:text-white mb-4">添加新分类</h2>
            
            <form onSubmit={handleSubmit} className="space-y-4">
              <div>
                <label htmlFor="name" className="block text-sm font-medium text-gray-700 dark:text-gray-300 mb-1">
                  分类名称 <span className="text-red-500">*</span>
                </label>
                <input
                  type="text"
                  id="name"
                  name="name"
                  value={formData.name}
                  onChange={handleChange}
                  className="w-full px-4 py-2 border border-gray-300 dark:border-gray-600 rounded-md shadow-sm focus:ring-blue-500 focus:border-blue-500 dark:bg-gray-700 dark:text-white"
                  required
                />
              </div>
              
              <div>
                <label htmlFor="description" className="block text-sm font-medium text-gray-700 dark:text-gray-300 mb-1">
                  分类描述 (可选)
                </label>
                <textarea
                  id="description"
                  name="description"
                  value={formData.description}
                  onChange={handleChange}
                  rows={3}
                  className="w-full px-4 py-2 border border-gray-300 dark:border-gray-600 rounded-md shadow-sm focus:ring-blue-500 focus:border-blue-500 dark:bg-gray-700 dark:text-white"
                ></textarea>
              </div>
              
              <div>
                <label htmlFor="icon" className="block text-sm font-medium text-gray-700 dark:text-gray-300 mb-1">
                  分类图标 (可选)
                </label>
                <div className="mt-1 flex items-center space-x-4">
                  <div className="flex-shrink-0">
                    <div className="relative">
                      {previewUrl ? (
                        <img
                          src={previewUrl}
                          alt="预览"
                          className="h-12 w-12 object-cover rounded-md border-2 border-gray-200 dark:border-gray-600 transition-all duration-300 hover:scale-110"
                        />
                      ) : (
                        <div className="h-12 w-12 rounded-md border-2 border-dashed border-gray-300 dark:border-gray-600 flex items-center justify-center text-gray-400">
                          <i class="fa-solid fa-image"></i>
                        </div>
                      )}
                    </div>
                  </div>
                  <div>
                    <input
                      id="icon"
                      name="icon"
                      type="file"
                      accept="image/*"
                      onChange={handleFileChange}
                      className="sr-only"
                    />
                    <label
                      htmlFor="icon"
                      className="px-3 py-1 border border-gray-300 dark:border-gray-600 rounded-md shadow-sm text-sm font-medium text-gray-700 dark:text-gray-300 bg-white dark:bg-gray-800 hover:bg-gray-50 dark:hover:bg-gray-700 transition-all duration-300 cursor-pointer"
                    >
                      <i class="fa-solid fa-upload mr-1"></i> 选择图片
                    </label>
                    {previewUrl && (
                      <button
                        type="button"
                        onClick={() => {
                          setPreviewUrl(null);
                          setFormData(prev => ({ ...prev, iconUrl: undefined }));
                        }}
                        className="ml-3 inline-flex items-center px-3 py-1 border border-red-300 dark:border-red-600 rounded-md shadow-sm text-sm font-medium text-red-700 dark:text-red-300 bg-white dark:bg-gray-800 hover:bg-red-50 dark:hover:bg-red-900/20 transition-all duration-300"
                      >
                        <i class="fa-solid fa-times mr-1"></i> 移除
                      </button>
                    )}
                  </div>
                </div>
                <p className="mt-1 text-xs text-gray-500 dark:text-gray-400">
                  上传图片作为分类图标，支持JPG、PNG格式，大小不超过5MB
                </p>
              </div>
              
              <div className="flex justify-end">
                <button
                  type="submit"
                  disabled={isSubmitting}
                  className="px-4 py-2 border border-transparent rounded-md shadow-sm text-sm font-medium text-white bg-blue-600 hover:bg-blue-700 disabled:opacity-50 disabled:cursor-not-allowed"
                >
                  {isSubmitting ? (
                    <>
                      <i class="fa-solid fa-spinner fa-spin mr-2"></i> 处理中...
                    </>
                  ) : (
                    '添加分类'
                  )}
                </button>
              </div>
            </form>
          </div>
        )}
        
        <div className="bg-white dark:bg-gray-800 rounded-lg shadow overflow-hidden border border-gray-200 dark:border-gray-700">
          <div className="p-6 border-b border-gray-200 dark:border-gray-700">
            <h2 className="text-lg font-medium text-gray-900 dark:text-white">现有分类</h2>
            <p className="mt-1 text-sm text-gray-500 dark:text-gray-400">
              点击分类卡片可以查看该分类下的资源，点击删除按钮可以删除分类
            </p>
          </div>
          
          {resourceTypes.length === 0 ? (
            <div className="text-center py-12">
              <div className="inline-flex items-center justify-center w-12 h-12 rounded-full bg-gray-100 dark:bg-gray-700 mb-4">
                <i class="fa-solid fa-folder-open text-gray-400 text-xl"></i>
              </div>
              <h3 className="text-lg font-medium text-gray-900 dark:text-white">暂无分类</h3>
              <p className="mt-1 text-gray-500 dark:text-gray-400">请添加您的第一个资源分类</p>
              <div className="mt-4">
                <button
                  onClick={() => setShowForm(true)}
                  className="inline-flex items-center px-4 py-2 border border-transparent rounded-md shadow-sm text-sm font-medium text-white bg-blue-600 hover:bg-blue-700"
                >
                  <i class="fa-solid fa-plus mr-2"></i> 添加分类
                </button>
              </div>
            </div>
          ) : (
            <div className="p-6">
              <div className="grid grid-cols-1 sm:grid-cols-2 lg:grid-cols-3 gap-6">
                {resourceTypes.map((type) => (
                  <ResourceTypeCard
                    key={type.id}
                    type={type}
                    onDelete={deleteResourceType}
                  />
                ))}
              </div>
            </div>
          )}
        </div>
        
        <div className="mt-6">
          <Link
            to="/"
            className="inline-flex items-center text-sm text-blue-600 dark:text-blue-400 hover:text-blue-800 dark:hover:text-blue-300"
          >
            <i class="fa-solid fa-arrow-left mr-1"></i> 返回首页
          </Link>
        </div>
      </main>
    </div>
  );
}